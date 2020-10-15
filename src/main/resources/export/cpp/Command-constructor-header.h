#set($command = $helper.getByName($command_name, $robot))
#set($params = $command.getProperty("Parameters").getValue())
#set($len = $params.size() - 2)
#set($last = $len + 1)
#if( $params.size() > 0 )
    explicit #class($command.name)(#if( $len >= 0 )#foreach($i in [0..$len])#param_declaration_cpp($params.get($i)), #end#end#param_declaration_cpp($params.get($last))#if (${command.getProperty("Requires").getValue()} != "None"), #class(${command.getProperty("Requires").getValue()})* #variable(${command.getProperty("Requires").getValue().toLowerCase()})#end);
#elseif (${command.getProperty("Requires").getValue()} == "None")
    explicit #class($command.name)();
#else
    explicit #class($command.name)(#class(${command.getProperty("Requires").getValue()})* #variable(${command.getProperty("Requires").getValue().toLowerCase()}));
#end
