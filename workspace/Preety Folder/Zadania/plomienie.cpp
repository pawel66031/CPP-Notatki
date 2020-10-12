//// Przesuwanie bitowe
//
//#include <bitset>
//#include <iostream>
//
//// "rotl" stands for "rotate left"
//std::bitset<4> rotl(std::bitset<4> bits)
//{
//    return (bits<<1) | (bits>>3);
//}
//
//int main()
//{
//	std::bitset<4> bits1{ 0b0001 };
//	std::cout << rotl(bits1) << '\n';
//
//	std::bitset<4> bits2{ 0b1001 };
//	std::cout << rotl(bits2) << '\n';
//
//	return 0;
//}

// Bit mask

//#include <iostream>
//#include <cstdint>
//
//int main()
//{
//    //constexpr std::uint_fast8_t isHungry{    1 << 0}; // 0000 0001
//    //constexpr std::uint_fast8_t isSad   {    1 << 1}; // 0000 0010
//    //constexpr std::uint_fast8_t isMad   {    1 << 2}; // 0000 0100
//    constexpr std::uint_fast8_t isHappy {    1 << 3}; // 0000 1000
//    constexpr std::uint_fast8_t isLaughing{  1 << 4}; // 0001 0000
//    constexpr std::uint_fast8_t isAsleep{    1 << 5}; // 0010 0000
//    //constexpr std::uint_fast8_t isDead{      1 << 6}; // 0100 0000
//    //constexpr std::uint_fast8_t isCrying{    1 << 7}; // 1000 0000
//
//    std::uint_fast8_t me{}; // Zerowa flaga (wszystkie bity są na 0)
//    me |= isHappy | isLaughing | isAsleep; // Wstaw wartości 1 (|=)
//    me &= ~isAsleep; // Wyzeruj wartości (&= ~)
//
//    std::cout << "Jestem szczęśliwy? " << static_cast<bool>(me & isHappy) << '\n';
//    std::cout << "Czy sie smieje? " << static_cast<bool>(me & isLaughing) << '\n';
//    std::cout << "Czy jestem spiacy? " << static_cast<bool>(me & isAsleep) << '\n';
//
//    return 0;
//}

// Quiz
//#include <cstdint>
//#include <iostream>
//
//int main()
//{
//    constexpr std::uint_fast8_t option_viewed{ 0x01 };
//    //constexpr std::uint_fast8_t option_edited{ 0x02 };
//    //constexpr std::uint_fast8_t option_favorited{ 0x04 };
//    //constexpr std::uint_fast8_t option_shared{ 0x08 };
//    //constexpr std::uint_fast8_t option_deleted{ 0x10 };
//
//    std::uint_fast8_t myArticleFlags{};
//
//    myArticleFlags |= option_viewed;
//
//    std::cout << myArticleFlags;
//
//    return 0;
//}

#include <iostream>

class Fire;

using Dimension = unsigned int; // zwraca wymiare
using Level = unsigned int;



class Fire
{
    int temperature_, power_;
public:
    Fire(): temperature_(80), power_(45)
    {
        // this->temperature_ = 80; // temperature_(80) po Fire() == this->temperature_ = 80
    }
    explicit Fire(int level): temperature_(level), power_(level/2)
    {

    }

    int getPower() { return power_; }//{ return this->power_; }
};

class Candle
{
    bool isLit;
public:
    Candle(): isLit(false)
    {

    }
    void ignite(Fire ploniesz)
    {
        isLit = (ploniesz.getPower()) ? true : false;
    }
    bool isBurning()
    {
        return isLit;
    }
};

class FuelTank
{
    Level currentFuelLevel_;
    const Level maxFuelLevel_;

    Dimension width_, height_, depth_;
public:
    FuelTank(): currentFuelLevel_(30), maxFuelLevel_(65), width_(15), height_(25), depth_(30)
    {

    }

    Dimension getWidth() const { return width_; }
    Dimension getHeight() const { return height_; } // { return this->height_; }
    Dimension getDepth() const { return depth_; } // { return this->depth_; }
    Level getFuel() const { return currentFuelLevel_; }

    Level pourFuelOut(Level levels)
    {
        currentFuelLevel_ -= levels;
        return currentFuelLevel_;
    }
    void pourFuelIn(Level levels)
    {
        currentFuelLevel_ = ((currentFuelLevel_ + levels) > maxFuelLevel_) ? maxFuelLevel_ : (currentFuelLevel_ + levels);
    }
};

class Lighter
{

    Dimension width_, height_, depth_;

    Level currentFuelLevel_;
    const Level maxFuelLevel_;

public:
    Lighter(): width_(5), height_(10), depth_(15), currentFuelLevel_(20), maxFuelLevel_(width_ * height_ * depth_)
    {

    }

    Dimension getWidth() const { return width_; }
    Dimension getHeight() const { return height_; } // { return this->height_; }
    Dimension getDepth() const { return depth_; } // { return this->depth_; }
    Level getFuel() const { return currentFuelLevel_; }


    Fire ignite()
    {
        return (currentFuelLevel_) ? Fire() : Fire(0);
    }
    void pourFuelIn(Level levels)
    {
        currentFuelLevel_ = ((currentFuelLevel_ + levels) > maxFuelLevel_) ? maxFuelLevel_ : (currentFuelLevel_ + levels);
    }

};

int main()
{
    FuelTank tanker;
    Lighter ligh;

    std::cout << "Lighter: " << ligh.getFuel() << '\n';
    std::cout << "Tanker: " << tanker.getFuel() << '\n';

    ligh.pourFuelIn(tanker.pourFuelOut(20));
    std::cout << '\n';

    std::cout << "Lighter: " << ligh.getFuel() << '\n';
    std::cout << "Tanker: " << tanker.getFuel() << '\n';

    Candle candle;
    std::cout << '\n';

    std::cout << candle.isBurning() << '\n';

    candle.ignite(ligh.ignite());

    std::cout << candle.isBurning() << '\n';

    //auto fire = ligh.ignite();

    //std::cout << fire.getPower() << '\n';

    return 0;
}













