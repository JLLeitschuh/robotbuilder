// The robot's subsystems
#foreach ($component in $components)
#if ("#type($component)" != "" 
&& ("#type($component)" == "frc2::SubsystemBase"
     || "#type($component)" == "frc2::PIDSubsystem"))
    #class($component.getName()) #variable($component.getName());
#end
#end

// Joysticks
#foreach ($component in $components)
#if ($helper.exportsTo("OI", $component)
     && "#type($component)" != "" 
     && "#base_type($component)" == "Joystick")
    #constructor($component)

#end
#end

frc::SendableChooser<frc2::Command*> m_chooser;
