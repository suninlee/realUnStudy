﻿#include <iostream>
#include <conio.h>

class Player
{
private:
    int Hp;
    int Att;

public:
    void StatusRender()
    {
        printf_s("플레이어의 능력치 ------------------------------------\n");
        printf_s("Hp %d\n", Hp);
        printf_s("Att %d\n", Att);
        printf_s("----------------------------------------------------\n");
    }

    int GetAtt()
    {
        return this->Att;
    }

    int IsDeath()
    {
        return this->Hp <= 0;
    }

    void Damage(int _Att)
    {
        printf_s("플레이어가 %d의 데미지를 입었습니다.\n", _Att);
        Hp -= _Att;
    }

public:
    Player(int _Hp, int _Att) : Hp(_Hp), Att(_Att)
    {

    }
};

class Monster
{
private:
    int Hp;
    int Att;

public:
    void StatusRender()
    {
        printf_s("몬스터의 능력치 -------------------------------------\n");
        printf_s("Hp %d\n", Hp);
        printf_s("Att %d\n", Att);
        printf_s("----------------------------------------------------\n");
    }

    int IsDeath()
    {
        return this->Hp <= 0;
    }

    int GetAtt()
    {
        return this->Att;
    }

    void Damage(int _Att)
    {
        printf_s("몬스터가 %d의 데미지를 입었습니다.\n", _Att);
        Hp -= _Att;
    }

public:
    Monster(int _Hp, int _Att) : Hp(_Hp), Att(_Att)
    {

    }

};

class FightZone
{
public:
    void Fight(Player* _Player, Monster* _Monster)
    {
        while (true)
        {
            system("cls");

            _Player->StatusRender();
            _Monster->StatusRender();
            _getch();
            _Monster->Damage(_Player->GetAtt());
            {
                system("cls");
                _Player->StatusRender();
                _Monster->StatusRender();
                printf_s("몬스터가 %d의 데미지를 입었습니다.\n", _Player->GetAtt());
            }
            if (true == _Monster->IsDeath())
            {
                printf_s("몬스터가 죽었습니다");
                return;
            }
            _getch();
            _Player->Damage(_Monster->GetAtt());
            {
                system("cls");
                _Player->StatusRender();
                _Monster->StatusRender();
                printf_s("몬스터가 %d의 데미지를 입었습니다.\n", _Player->GetAtt());
                printf_s("플레이어가 %d의 데미지를 입었습니다.\n", _Monster->GetAtt());
            }
            if (true == _Player->IsDeath())
            {
                printf_s("플레이어가 죽었습니다");
                return;
            }
            _getch();
        }
    }
};

// 전역 함수나 전역 변수는 객체와 멀어진겁니다.
// main 객체지향에서 => 
int main()
{
    Player NewPlayer = Player(100, 10);
    Monster NewMonster = Monster(100, 10);
    FightZone Zone;

    Zone.Fight(&NewPlayer, &NewMonster);
}
