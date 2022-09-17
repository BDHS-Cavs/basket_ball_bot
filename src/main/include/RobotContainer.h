// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

// frc includes
#include <frc/Joystick.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/XboxController.h>

#include <frc2/command/Command.h>
#include <frc2/command/button/JoystickButton.h>

// our includes
#include "subsystems/Drive.h"

class RobotContainer {

public:

    frc2::Command* GetAutonomousCommand();
    static RobotContainer* GetInstance();

    // The robot's subsystems
    Drive     m_drive;

    // Get the control values
    frc::Joystick *getJoystick();
    frc::XboxController *getController();

private:

    RobotContainer();

    // Joysticks
    frc::Joystick m_joystick{0};
    frc::XboxController m_controller{1};

    frc::SendableChooser<frc2::Command*> m_chooser;
    AutonomousCommand m_autonomousCommand;
    static RobotContainer* m_robotContainer;

    void ConfigureButtonBindings();
};
