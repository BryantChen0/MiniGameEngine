#pragma once
#include <vector>

template<typename T>
class ObjectManager
{
private:
    std::vector<T> objects;

public:
    //用任意参数，直接在 vector 里构造一个 T 对象，并返回它的引用。
    template<typename... Args>//可变模板参数（variadic template）
    T& spawn(Args&&... args) {// 万能引用 + 参数包
        //这个和push的差别在于，其直接构造对象，但是push需要临时对象进行拷贝或者移入其中
        return objects.emplace_back(
            std::forward<Args>(args)... //完美转发(perfect forwarding):保持参数原来的“左值/右值属性”
        );
    }

    void update(float dt)
    {
        for (auto& obj : objects)
        {
            obj.update(dt);
        }
    }

    void removeDead()
    {
        for (int i = objects.size() - 1; i >= 0; --i)
        {
            if (!objects[i].isAlive())
            {
                objects.erase(objects.begin() + i);
            }
        }
    }

    auto& getObjects()
    {
        return objects;
    }

    //数据结构层面的清除
    void clear()
    {
        objects.clear();
    }

    //语义层面的重置状态
    void reset()
    {
        clear();
    }
    
};