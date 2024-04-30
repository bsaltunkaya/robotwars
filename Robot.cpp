//
// Created by Bekir Sadık Altunkaya on 22.04.2024.
//

#include "Robot.h"
//set initial static counter variables to 0
int Robot::s_count=0;
int optimusprime::s_optimusprimeCount=0;
int robocop::s_robocopCount=0;
int roomba::s_roombaCount=0;
int bulldozer::s_bulldozerCount=0;
int kamikaze::s_kamikazeCount=0;



Robot::Robot()
{
  m_Strength=0; m_HitPoints=0; name="Unknown";
  s_count++;
  moved=false;
}
Robot::Robot(int newStrength, int newHitPoints, std::string newName)
{
  m_Strength=newStrength; m_HitPoints=newHitPoints; name=newName;
  s_count++;
  moved=false;
}
std::string Robot::getName()const
{
  return name;
}
std::string Robot::getType()
{
  std::cerr<<"\nAttempted to return unspecified robot property!\n"<<
          "Contact the programmer about this error.\n";
  exit(1);
}
int Robot::getStrength() const
{
  return m_Strength;
}
int Robot::getHitPoints() const
{
  return m_HitPoints;
}
void Robot::setName(const std::string &newName)
{
  name=newName;
}
void Robot::setStrength(int newStrength)
{
  m_Strength=newStrength;
}
void Robot::setHitPoints(int newHitPoints)
{
  m_HitPoints=newHitPoints;
}
int Robot::getDamage()//base getdamage, humanic and others are build on top of this
{
  return rand()%this->getStrength()+1;
}
bool Robot::fight(Robot &opponent) {//main fight function
  if (this->getHitPoints() <= 0) {
    std::cout << this->getName() << " is destroyed and cannot fight.\n";
    return false;  // the robot cannot fight because it's destroyed
  }

  // perform attack if the robot has hit points
  int attackDamage = this->getDamage();
  std::cout << this->getName() << " attacks " << opponent.getName()
            << " with " << attackDamage << " damage.\n";

  opponent.setHitPoints(opponent.getHitPoints() - attackDamage);

  // check if the opponent is destroyed
  if (opponent.getHitPoints() <= 0) {

    return true;  // attacker wins
  }

  return false; // defender survives
}int humanic::getDamage()
{
  if(rand()%10==0)//tac nuke
    return Robot::getDamage()+50;
  else
    return Robot::getDamage();
}

std::string optimusprime::getType()
{
  return "optimusprime";
}
optimusprime::optimusprime()
{
  this->setStrength(100); this->setHitPoints(100); this->setName("optimusprime_"+std::to_string(s_optimusprimeCount));
  s_optimusprimeCount++;

}
optimusprime::optimusprime(int newStrength, int newHitPoints, std::string newName)
{
  this->setStrength(newStrength); this->setHitPoints(newHitPoints); this->setName(newName);
  s_optimusprimeCount++;
}
int optimusprime::getDamage()
{//strong attack doubling the amount of damage
  if(rand()%100<15)
    return humanic::getDamage()*2;
  else
    return humanic::getDamage()*2;
}

std::string robocop::getType()
{
  return "robocop";
}
robocop::robocop()
{
  this->setStrength(30); this->setStrength(40); this->setName("robocop_"+std::to_string(s_robocopCount));
  s_robocopCount++;
}
robocop::robocop(int newStrength, int newHitPoints, std::string newName)
{
  this->setStrength(newStrength); this->setHitPoints(newHitPoints); this->setName(newName);
  s_robocopCount++;
}
int robocop::getDamage()
{
  return humanic::getDamage();
}

std::string roomba::getType()
{
  return "roomba";
}
roomba::roomba()
{
  this->setStrength(3); this->setHitPoints(10); this->setName("roomba_"+std::to_string(s_roombaCount));
  s_roombaCount++;
}
roomba::roomba(int newStrength, int newHitPoints, std::string newName)
{
  this->setStrength(newStrength); this->setHitPoints(newHitPoints); this->setName(newName);
  s_roombaCount++;
}
int roomba::getDamage()
{
  return 2*Robot::getDamage();
}

std::string bulldozer::getType()
{
  return "bulldozer";
}
bulldozer::bulldozer()
{
  this->setStrength(50); this->setHitPoints(200); this->setName("bulldozer_"+std::to_string(s_bulldozerCount));
  s_bulldozerCount++;
}
bulldozer::bulldozer(int newStrength, int newHitPoints, std::string newName)
{
  this->setStrength(newStrength); this->setHitPoints(newHitPoints); this->setName(newName);
  s_bulldozerCount++;
}
int bulldozer::getDamage()
{
  return Robot::getDamage();
}

std::string kamikaze::getType()
{
  return "kamikaze";
}
kamikaze::kamikaze()
{
  this->setStrength(10); this->setHitPoints(10); this->setName("kamikaze_"+std::to_string(s_kamikazeCount));
  s_kamikazeCount++;
}
kamikaze::kamikaze(int newStrength, int newHitPoints, std::string newName)
{
  this->setStrength(newStrength); this->setHitPoints(newHitPoints); this->setName(newName);
  s_kamikazeCount++;
}
int kamikaze::getDamage()
{
  this->setHitPoints(0);
  return this->getStrength();
}