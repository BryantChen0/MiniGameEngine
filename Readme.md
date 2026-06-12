# 🕹 Mini2D Game Engine (C++ / SDL2)

## 📌 项目简介

Mini2D 是一个使用 **C++ + SDL2** 从零实现的最小可用 2D 游戏引擎，用于学习游戏引擎的核心架构与运行机制，并基于该引擎开发一个类似 *Flappy Bird* 的小游戏。

本项目强调：

> **Game Engine = Data + Update + Render**

通过该项目理解：

* 游戏主循环机制
* 实体与生命周期管理
* 渲染与输入系统解耦
* 简单物理与碰撞检测
* 资源管理与缓存机制

---

## 🎯 项目目标

* 从零实现一个可运行的 2D 游戏引擎
* 理解游戏循环（Game Loop）的本质
* 掌握模块化设计与系统解耦思想
* 实现一个完整可玩的 2D 小游戏
* 形成基础的“引擎 + 游戏”开发思维

---

## 🚫 项目范围（刻意简化）

本项目刻意不涉及以下内容：

* ❌ 3D 渲染
* ❌ 复杂物理引擎（刚体/约束系统）
* ❌ 脚本系统（Lua / Python）
* ❌ 多线程架构
* ❌ Shader / 光照系统

目标是保持：

> **小而完整，而不是大而复杂**

---

## 🧠 引擎架构概览

核心运行流程：

```
Input → Update → Render
```

整体结构：

```
Game Loop
 ├── Input System
 ├── Scene System
 ├── Entity System
 ├── Physics System
 ├── Render System
 └── Image System
```

---

## 🧩 核心模块

### 🎮 Game Loop

负责驱动整个引擎运行：

* 处理输入
* 更新逻辑
* 渲染画面
* 支持 delta time

---

### 🖼 Render System

负责所有渲染相关操作：

* 清屏
* 绘制 Texture
* 渲染实体对象

---

### ⌨ Input System

负责输入处理：

* 键盘按下 / 松开
* 退出事件处理

---

### 🧱 Entity System（引擎核心）

游戏对象分为两个部分：
* Object：纯粹数据对象
* Entity：逻辑对象的父类，继承Object数据对象的数据

同时具有Object Manager模版类支持多个相同对象的动态创建与销毁。

---

### 🌍 Physics System

提供基础物理能力：

* 基础运动（速度驱动位置）
* 重力模拟
* AABB 碰撞检测

---

### 🎬 Scene System

管理游戏状态：

* Game Scene（游戏中）
* Game Over Scene（结束界面）
* 支持场景切换

---

### 🧠 Image System

资源管理模块：

* 加载 PNG 纹理（SDL2_image）
* 资源缓存（避免重复加载）
* 提供统一访问接口

---

## 🎮 当前实现的游戏

基于该引擎实现了一个类似 Flappy Bird 的小游戏：

### ✔ 游戏机制

* 自动生成管道（Pipe）
* 玩家控制跳跃
* 重力系统
* 碰撞检测
* 死亡判定
* 场景切换（Game / GameOver）

---

### ✔ 游戏特性

* delta time 驱动
* 随机管道生成
* 基础物理模拟
* 实时碰撞检测
* 简单资源加载系统

---

## 🧪 当前完成状态

✔ 已完成核心引擎框架
✔ 已完成基础游戏玩法
✔ 已实现 Scene 切换
✔ 已实现碰撞体积系统
✔ 已实现实体管理系统
✔ 已实现资源加载系统

---

## 🚀 下一步开发计划

* UI 系统（Score / Game Over UI）
* 分数系统（Score System）
* Restart 机制（重新开始游戏）

---

## 🛠 技术栈

| 类型     | 技术         |
| ------ | ---------- |
| 语言     | C++        |
| 图形库    | SDL2       |
| 图片加载   | SDL2_image |
| 音频（可选） | SDL2_mixer |

---

## 📦 最终目标

通过该引擎实现：

> 一个完整可玩的 2D 小游戏，并理解其底层运行机制

---

## 📌 项目定位

本项目不是商业引擎，而是：

> **用于学习游戏引擎架构的最小实验性项目（Minimal Engine Prototype）**

---

