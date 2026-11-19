# ESP32 开发资料索引

## 项目入口

- [S1～S7 学习路线](docs/S1-S7-学习路线.md)记录项目目标、各阶段交付和验证进度。继续当前实验时，直接看[当前下一步](docs/S1-S7-学习路线.md#当前下一步)。
- [ESP-IDF `hello_world` 示例](examples/hello_world/README.md)是 S1 上板验证的代码入口，应用入口在 [`hello_world_main.c`](examples/hello_world/main/hello_world_main.c)。
- [S7 长期稳定与扩展](docs/S7-长期稳定与扩展.md)补充 OTA、能力扩展和自制 PCB 的阶段安排。

## 核心板与外设接线（仓库内图文资料）

| 要查的内容 | 资料 |
| --- | --- |
| 本项目 ESP32-S3 N16R8 核心板的供电、复位、UART/USB 和板载 `WS2812B` | [核心板原理图](docs/references/core-board/ESP32-S3-N16R8-核心板原理图.pdf) |
| 开发板正面的元件名称和位置 | [ESP32-S3 N16R8 实物元件标注图](docs/references/core-board/ESP32-S3-N16R8-实物元件标注.png) |
| 0.91 寸 OLED、1.54 寸彩屏和喇叭接线 | [OLED 图 1](docs/references/wiring/面包板-0.91寸OLED-接线图1.jpg) · [OLED 图 2](docs/references/wiring/面包板-0.91寸OLED-接线图2.jpg) · [1.54 寸彩屏](docs/references/wiring/面包板-1.54寸彩屏-接线图.png) · [喇叭](docs/references/wiring/喇叭-接线方式.png) |
| 小智 S3 智能扩展板原理图 | [V1.6](docs/references/expansion-board/XZ-AI-KZB-V1.6-原理图.pdf) · [V1.7](docs/references/expansion-board/XZ-AI-KZB-V1.7-原理图.pdf) · [V1.8](docs/references/expansion-board/XZ-AI-KZB-V1.8-原理图.pdf)（按实物丝印选择） |
| 扩展板引脚、尺寸和装配 | [V1.7 引脚定义](docs/references/expansion-board/扩展板-V1.7-引脚定义.jpg) · [V1.7 尺寸图](docs/references/expansion-board/扩展板-V1.7-尺寸图.png) · [AI 智能扩展板尺寸图](docs/references/expansion-board/AI智能扩展板-尺寸图.png) |
| 小智控制固件的外设接线 | [小智控制固件接线说明 PDF](docs/references/expansion-board/小智控制固件-接线说明.pdf)（文档按 42 引脚果云版编写） |

## 小智刷机与配网图文指南（仓库内图文资料）

| 要查的内容 | 资料 |
| --- | --- |
| 烧录小智预编译固件 | [小智刷机教程](docs/references/guides/小智-刷机教程.pdf) · [烧录设置画面](docs/references/guides/FlashDownloadTool-烧录设置画面.png) |
| 小智 Wi-Fi 配网、设备激活和状态灯 | [Wi-Fi 配网与使用教程](docs/references/guides/小智-WiFi配网与使用教程.pdf) |
| 固件命名与烧录备注 | [固件更新与命名说明](docs/references/guides/小智固件-更新与命名说明.txt) · [小智控制固件烧录说明](docs/references/guides/小智控制固件-烧录说明.txt) |

小智刷机教程里的 `0x0` 用于教程指定的合并镜像。项目自行构建的 ESP-IDF 示例使用构建生成的烧录参数，当前实验见[上板验证步骤](docs/S1-S7-学习路线.md#s1-待验证)。

## 本地留底资料（位于 `docs/references/local/`，已由 `.gitignore` 忽略，不随仓库分发）

| 类别 | 本地路径 |
| --- | --- |
| Windows CH340 串口驱动 | [CH340 驱动安装程序](docs/references/local/tools/CH341SER-CH340驱动.exe) |
| Flash Download Tool（保留最新 3.9.9 R2） | [Flash Download Tool 3.9.9 R2](docs/references/local/tools/flash_download_tool_3.9.9_R2.zip) |
| 面包板与烧录教程视频 | [面包板安装技巧视频](docs/references/local/videos/面包板-安装技巧视频.mp4) · [小智 AI 烧录固件视频](docs/references/local/videos/小智AI-烧录固件视频.mp4) · [小智扩展板安装烧录视频](docs/references/local/videos/小智扩展板-安装烧录视频.mp4) |
| 小智普通版预编译固件 | [0.91 寸 OLED](docs/references/local/xiaozhi-firmware-src/普通版固件/0.91寸OLED固件/) · [1.3 寸](docs/references/local/xiaozhi-firmware-src/普通版固件/1.3寸液晶屏固件/) · [1.54 寸](docs/references/local/xiaozhi-firmware-src/普通版固件/1.54寸液晶屏固件/) · [1.8 寸](docs/references/local/xiaozhi-firmware-src/普通版固件/1.8寸液晶屏固件/) · [2.0 寸](docs/references/local/xiaozhi-firmware-src/普通版固件/2.0液晶屏固件/) |
| 小智控制版预编译固件（电机/舵机/灯） | [小智控制固件目录](docs/references/local/xiaozhi-firmware-src/控制版固件/) |
| 小智历史源码归档 | [0.9.2](docs/references/local/xiaozhi-firmware-src/源码归档/xiaozhi-esp32-0.9.2.zip) · [2.5.2 S3](docs/references/local/xiaozhi-firmware-src/源码归档/xiaozhi-esp32-2.5.2S3源码.rar) · [`main203` 彩屏版](docs/references/local/xiaozhi-firmware-src/源码归档/xiaozhi-esp32-main203彩屏固件源码.rar) |

---

目录约定：核心板、扩展板、外设接线与图文教程按用途分别收在 [`core-board/`](docs/references/core-board/)、[`expansion-board/`](docs/references/expansion-board/)、[`wiring/`](docs/references/wiring/) 和 [`guides/`](docs/references/guides/)（均入库追踪）；驱动工具、教程视频及第三方固件/源码统一保存在 [`docs/references/local/`](docs/references/local/) 本地留底，不提交到 Git 仓库。新增资料时，按对应分类归档并同步更新此索引页。
