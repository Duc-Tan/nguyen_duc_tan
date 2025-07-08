#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_wifi.h"
#include "nvs_flash.h"

TaskHandle_t task_1;
TaskHandle_t task_2;
QueueHandle_t xQueue1;

void blink_led(void*){
    gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);
    while(1){
        gpio_set_level(GPIO_NUM_2, 0);
        vTaskDelay(pdMS_TO_TICKS(1000));
        gpio_set_level(GPIO_NUM_2, 1);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

int global_var;
void read_sensor_data(void* param){
    int ss_data = 0;
    while(1){
        ss_data++;
        //global_var = ss_data;
        xQueueSend(xQueue1, &ss_data, pdMS_TO_TICKS(10000));
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

}

static void event_handler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data)
{
    if(event_base == WIFI_EVENT)
    {
        switch(event_id){
            case WIFI_EVENT_WIFI_READY:
                printf("WiFi Ready\n");
                break;
            case WIFI_EVENT_STA_START:
                printf("WiFi station start\n");
                esp_wifi_connect();
                break;
            case WIFI_EVENT_STA_CONNECTED:
                printf("WiFi connect successfully\n");
                break;
            case WIFI_EVENT_STA_DISCONNECTED:
                printf("WiFi disconnected\n");
                break;
            default:
                printf("ID: %ld", event_id);
                break;
        }
    }
}

void app_main(void)
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    gpio_set_direction(GPIO_NUM_0, GPIO_MODE_INPUT);

    xQueue1 = xQueueCreate(100, sizeof(int));
    xTaskCreate(
        blink_led,
        "blink_led",
        2048,
        NULL,
        1,
        &task_1
    );

    xTaskCreate(
        read_sensor_data,
        "read_sensor",
        2048,
        NULL,
        1,
        &task_2
    );
    
    

    int ss_data;
    wifi_init_config_t wifi_init_cfg = WIFI_INIT_CONFIG_DEFAULT();
    if(esp_wifi_init(&wifi_init_cfg) == ESP_OK){
        printf("Ket noi wifi thanh cong\n");
    }
    else{
        printf("Ket noi wifi khong thanh cong\n");
        return;
    }
    esp_event_handler_instance_t instance_any_id;
    esp_event_handler_instance_register(WIFI_EVENT,
        ESP_EVENT_ANY_ID, 
        &event_handler, 
        NULL, 
        &instance_any_id);
    wifi_config_t wifi_config = { 
        .sta = {
            .ssid ="VAN TRUONG",
            .password = "1234567890",
        }
    };
    esp_wifi_set_mode(WIFI_MODE_STA);
    esp_wifi_set_config(WIFI_IF_STA, &wifi_config);
    esp_wifi_start();

    while(1){
        int num_data = uxQueueMessagesWaiting(xQueue1);
        printf("[app main] sensor data: ");
        for(int i = 0; i < num_data; i++){
            xQueueReceive(xQueue1, &ss_data, pdMS_TO_TICKS(1000));
            printf("%d ", ss_data);
        }
        printf("\n");
        vTaskDelay(pdMS_TO_TICKS(10000));
    }
}
