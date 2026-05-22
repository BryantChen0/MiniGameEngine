#ifndef MINIGAMEENGINE_MATH_H
#define MINIGAMEENGINE_MATH_H
#pragma once
#include <cmath>
//工具库，存放一系列数学工具

namespace Math {
    //模板函数，不需要header和source分开存放
    template<typename T1, typename T2>
    auto pow(T1 base, T2 exponent){
        return std::pow(base,exponent);
    };
}


#endif //MINIGAMEENGINE_MATH_H
