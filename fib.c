#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "esp_log.h"
#include "freertos/task.h"
#include <math.h>

int fib(int n) {
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, n) / sqrt(5));
}

void app_main(void){
    char* task = pcTaskGetName(NULL);
    
    for(int n = 0; n < 20; n++){
        ESP_LOGI(task, "%d, %i\n", fib(n), n);
    }
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
