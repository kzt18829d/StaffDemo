#ifndef STAFFDEMO_SIGNAL_H
#define STAFFDEMO_SIGNAL_H
#include <functional>
#include <map>
#include <algorithm>

template <typename ... Args>
class Signal {
public:
    using SlotID = int;
    using SlotType = std::function<void(Args...)>;

private:
    std::map<SlotID, SlotType> slots;
    SlotID newSlotID{0};

public:
    Signal() = default;
    ~Signal() = default;
    Signal(const Signal& other) = delete;
    Signal(Signal&& other) = delete;
    Signal& operator=(const Signal& other) = delete;
    Signal& operator=(const Signal&&) = delete;

    SlotID Connect(SlotType&& slotType) {
        SlotID id = newSlotID++;
        slots[id] = std::forward<SlotType>(slotType);
        return id;
    }

    SlotID Connect(const SlotType& slotType) {
        SlotID id = newSlotID++;
        slots[id] = slots;
        return id;
    }

    bool Disconnect(SlotID id) {
        return slots.erase(id);
    }

    void Emit(Args ... args) {
        auto currentSlots = slots;
        std::for_each(currentSlots.begin(), currentSlots.end(), [&](auto current){ if (current.second) current.second(std::forward<args>()...);});
    }

    void operator()(Args ... args) const { Emit(std::forward<args>()...); }

};


#endif //STAFFDEMO_SIGNAL_H
