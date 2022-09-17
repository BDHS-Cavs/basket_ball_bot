// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/RunCommand.h>
#include <frc/smartdashboard/SmartDashboard.h>

RobotContainer* RobotContainer::m_robotContainer = NULL;

RobotContainer::RobotContainer() : m_autonomousCommand() {
	
    ConfigureButtonBindings();

    // Set up default drive command
    m_drive.SetDefaultCommand(frc2::RunCommand(
        [this]
        {
            m_drive.Motivate(
                m_joystick.GetY(),
                m_joystick.GetX());
        },
         {&m_drive}));

}

RobotContainer* RobotContainer::GetInstance() {
    if (m_robotContainer == NULL) {
        m_robotContainer = new RobotContainer();
    }
    return(m_robotContainer);
}

void RobotContainer::ConfigureButtonBindings() {

}

frc::Joystick* RobotContainer::getJoystick() {
   return &m_joystick;
}
frc::XboxController* RobotContainer::getController() {
   return &m_controller;
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // The selected command will be run in autonomous
  return m_chooser.GetSelected();
}
