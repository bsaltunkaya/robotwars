//
// Created by Bekir Sadık Altunkaya on 22.04.2024.
//

#ifndef ROBOT_WARS_ROBOT_H
#define ROBOT_WARS_ROBOT_H
#include <iostream>
#include <string>
#include <cstdlib>

class Robot
  {
public:
    Robot();
    Robot(int newStrength, int newHitPoints,std::string newName);
    virtual ~Robot() {}
    void resetMoved() { moved = false; }
    bool hasMoved() const { return moved; }
    void setMoved(bool value) { moved = value; }
    std::string getName()const;
    virtual std::string getType();
    int getStrength()const;
    int getHitPoints()const;
    void setName(const std::string& newName);
    void setStrength(int newStrength);
    void  setHitPoints(int newHitPoints);
    virtual int getDamage();
    virtual bool fight(Robot& opponent);

private:
    int m_Strength,m_HitPoints;
    std::string name;
    static int s_count;
    bool moved = false;

  };
class humanic:public Robot
  {
  public:
  int getDamage() override;
  };
class optimusprime:public humanic
  {
  public:
  std::string getType()override;

  optimusprime();
  optimusprime(int newStrength, int newHitPoints,std::string newName);
  int getDamage() override;
private:
    static int s_optimusprimeCount;
  };
class robocop:public humanic
  {
  public:
  std::string getType()override;
  robocop();
  robocop(int newStrength, int newHitPoints,std::string newName);
  int getDamage() override;
private:
    static int s_robocopCount;
  };
class roomba:public Robot
{
public:
  std::string getType()override;
  roomba();
  roomba(int newStrength, int newHitPoints,std::string newName);
  int getDamage() override;
private:
  static int s_roombaCount;
};
class bulldozer:public Robot
{
public:
  std::string getType()override;
  bulldozer();
  bulldozer(int newStrength, int newHitPoints,std::string newName);
  int getDamage() override;
private:
  static int s_bulldozerCount;
};
class kamikaze:public Robot
{
public:
  std::string getType()override;
  kamikaze();
  kamikaze(int newStrength, int newHitPoints,std::string newName);
  int getDamage() override;
private:
  static int s_kamikazeCount;
};




#endif //ROBOT_WARS_ROBOT_H
