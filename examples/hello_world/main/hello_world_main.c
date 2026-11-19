/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>               /* C 标准库的 printf、fflush 和 stdout。 */
#include <inttypes.h>            /* 提供 PRIu32 格式宏，并引入 uint32_t 类型。 */
#include "sdkconfig.h"           /* 构建生成的头文件，定义 CONFIG_IDF_TARGET。 */
#include "freertos/FreeRTOS.h"   /* FreeRTOS 基础定义，间接引入 portTICK_PERIOD_MS。 */
#include "freertos/task.h"       /* FreeRTOS 任务接口，声明 vTaskDelay。 */
#include "esp_chip_info.h"       /* 芯片信息类型、查询函数和 CHIP_FEATURE_* 标志。 */
#include "esp_flash.h"           /* 声明 esp_flash_get_size，并间接引入 ESP_OK。 */
#include "esp_system.h"          /* 声明重启和查询最小剩余堆内存的函数。 */

/* ESP-IDF 启动后，由 FreeRTOS 的主任务调用这个入口。 */
void app_main(void)
{
    printf("Hello from my ESP32!\n");

    /* Print chip information */
    esp_chip_info_t chip_info;
    uint32_t flash_size;
    /* 把局部变量的地址传给库函数，让它填入芯片信息。 */
    esp_chip_info(&chip_info);
    /* 用按位与检查芯片支持的无线功能。 */
    printf("This is %s chip with %d CPU core(s), %s%s%s%s, ",
           CONFIG_IDF_TARGET,
           chip_info.cores,
           (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "WiFi/" : "",
           (chip_info.features & CHIP_FEATURE_BT) ? "BT" : "",
           (chip_info.features & CHIP_FEATURE_BLE) ? "BLE" : "",
           (chip_info.features & CHIP_FEATURE_IEEE802154) ? ", 802.15.4 (Zigbee/Thread)" : "");

    /* 芯片版本号按主版本乘以 100 再加次版本编码。 */
    unsigned major_rev = chip_info.revision / 100;
    unsigned minor_rev = chip_info.revision % 100;
    printf("silicon revision v%d.%d, ", major_rev, minor_rev);
    /* NULL 选用默认 Flash，容量写入 flash_size，返回值表示是否成功。 */
    if(esp_flash_get_size(NULL, &flash_size) != ESP_OK) {
        printf("Get flash size failed");
        return;
    }

    printf("%" PRIu32 "MB %s flash\n", flash_size / (uint32_t)(1024 * 1024),
           (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    printf("Minimum free heap size: %" PRIu32 " bytes\n", esp_get_minimum_free_heap_size());

    /* 每轮打印倒计时后，让当前任务等待约一秒。 */
    for (int i = 10; i >= 0; i--) {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    /* 先刷新标准输出缓冲区，再重启芯片。 */
    fflush(stdout);
    esp_restart();
}
