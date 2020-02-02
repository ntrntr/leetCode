using System.Collections.Generic;

namespace Test.Problems
{
    public class HeadFirst
    {
        
    }

//    public class Machine
//    {
//        
//    }
//
//    public class Light
//    {
//        public void on()
//        {
//            
//        }
//    }
//
//    public class TV
//    {
//        public void on()
//        {
//            
//        }
//    }
//    
//    public class SimpleRemoteController
//    {
//        private object[] _machines;
//        private Invorker _invorker;
//
//        public SimpleRemoteController()
//        {
//            _machines = new object[7];
//            _invorker = new Invorker();
//        }
//
//        public void SetMachine(int slot, Machine machine)
//        {
//            _machines[slot] = machine;
//        }
//
//        public void onButtonPress(int slot)
//        {
//            var machine = _machines[slot];
//            _invorker.onExecute(machine);
//        }
//        
//        public void offButtonPress(int slot)
//        {
//            ...
//        }
//    }
//
//    public class Invorker
//    {
//        public void onExecute(object machine)
//        {
//            if (machine is Light)
//            {
//                var light = machine as Light;
//                light.on();
//            }
//            else if (machine is TV)
//            {
//                var tv = machine as Light;
//                tv.on();
//            }
//            ...
//        }
//    }
//
//    public interface Command
//    {
//        void execute();
//    }
//
//    public class LightOnCommand : Command
//    {
//        Light light;
//
//        public LightOnCommand(Light light)
//        {
//            this.light = light;
//        }
//
//        public void execute()
//        {
//            light.on();
//        }
//    }
//    
//    public class SimpleRemoteControl {
//        Command slot;
//        public SimpleRemoteControl() {}
//        public void setCommand(Command command) {
//            slot = command;
//        }
//        public void buttonWasPressed() {
//            slot.execute();
//        }
//    }
//    
//    public class RemoteControlTest {
//        public static void main(string[] args) {
//            SimpleRemoteControl remote = new SimpleRemoteControl();
//            Light light = new Light();
//            LightOnCommand lightOn = new LightOnCommand(light);
//            remote.setCommand(lightOn);
//            remote.buttonWasPressed();
//        }
//    }
//
//    public class RemoteControl
//    {
//        Command[] onCommands;
//        Command[] offCommands;
//
//        public RemoteControl()
//        {
//            onCommands = new Command[7];
//            offCommands = new Command[7];
//            Command noCommand = new NoCommand();
//            for (int i = 0; i < 7; i++)
//            {
//                onCommands[i] = noCommand;
//                offCommands[i] = noCommand;
//            }
//        }
//
//        public void setCommand(int slot, Command onCommand, Command offCommand)
//        {
//            onCommands[slot] = onCommand;
//            offCommands[slot] = offCommand;
//        }
//
//        public void onButtonWasPushed(int slot)
//        {
//            onCommands[slot].execute();
//        }
//
//        public void offButtonWasPushed(int slot)
//        {
//            offCommands[slot].execute();
//        }
//    }
//
//    public class NoCommand : Command
//    {
//        public void execute()
//        {
//        }
//    }
//
//
//    public class ActiveObjectEngine
//    {
//        LinkedList<Command> _commands = new LinkedList<Command>();
//
//        public void addCommand(Command c)
//        {
//            _commands.AddLast(c);
//        }
//
//        public void Run()
//        {
//            while (_commands.Count > 0)
//            {
//                var c = _commands.First;
//                _commands.RemoveFirst();
//                c.Value.execute();
//            }
//        }
//    }
//
//    public class SleepCommand : Command
//    {
//        private long _sleepTime = 0;
//        private long _startTime = 0;
//
//        private bool _isStarted = false;
//
//        private ActiveObjectEngine _engine = null;
//
//        private Command _wakeupCommand = null;
//        public SleepCommand(long milliseconds, ActiveObjectEngine e, Command wakeUpCommand)
//        {
//            _sleepTime = milliseconds;
//            _engine = e;
//            _wakeupCommand = wakeUpCommand;
//        }
//        
//        public void execute()
//        {
//            long currentTime = System.DateTime.Now.Millisecond;
//            if (!_isStarted)
//            {
//                _isStarted = true;
//                _startTime = currentTime;
//                _engine.addCommand(this);
//            }
//            else if ((currentTime - _startTime) < _sleepTime)
//            {
//                _engine.addCommand(this);
//            }
//            else
//            {
//                _engine.addCommand(_wakeupCommand);
//            }
//        }
//    }
//
//    public class TestSleep
//    {
//        public class WakeUpCommand:Command
//        {
//            public void execute()
//            {
//            }
//        }
//        
//        public static void main(string[] args)
//        {
//            Command wakeUp = new WakeUpCommand();
//            ActiveObjectEngine e = new ActiveObjectEngine();
//            SleepCommand sleepCommand = new SleepCommand(1000, e, wakeUp);
//            e.addCommand(sleepCommand);
//            e.Run();
//            
//        }
//    }
    
}