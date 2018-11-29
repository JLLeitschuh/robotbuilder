#set($command = $helper.getByName($command-name, $robot))
#set($subsystem = $command.getProperty("Requires").getValue())
#set($subsystem-instance = $helper.getByName($subsystem,$robot))
#foreach ($component in $components)
#if ($component.name == $command.getProperty("Input").getValue() && $component.getSubsystem().equals($subsystem.concat(" ")))
        return Robot.#variable($subsystem).get#class($component.name)().pidGet();
#end
#end
