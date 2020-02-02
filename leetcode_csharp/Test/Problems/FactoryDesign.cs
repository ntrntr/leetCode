using System;
using System.Collections.Generic;
using System.Reflection;

namespace Test.Problems
{
    public class FactoryDesign
    {
        public static void main(string[] args)
        {
            var test = new FactoryDesign(new SimpleCarFactory());
            Console.WriteLine(test.GetMaxCarSpeed("SportCar"));
        }

        private SimpleCarFactory _factory;
        
        public FactoryDesign(SimpleCarFactory factory)
        {
            _factory = factory;
        }

        public float GetMaxCarSpeed(string type)
        {

            var car = _factory.CreateCar(type);
            return car.GetMaxCarSpeed();
        }     
    }

    public class SimpleCarFactory
    {
        public ICar CreateCar(string type)
        {
            ICar car;
            if (type == "SportCar")
            {
                car = new SportCar();
            }
            else if (type == "JeepCar")
            {
                car = new JeepCar();
            }else if (type == "HatchbackCar")
            {
                car = new JeepCar();
            }
            else
            {
                car = SportCar();
            }

            return car;
        }
    }
    
    public enum CarType
    {
        SportCarType = 0,
        JeepCarType = 1,
        HatchbackCarType = 2
    }
    
    public partial class SportCar : ICar
    {

        public CarType GetCarType()
        {
            return CarType.SportCarType;
        }

        public float GetMaxCarSpeed()
        {
            return 200f;
        }
    }

    public class JeepCar : ICar
    {
        public CarType GetCarType()
        {
            return CarType.JeepCarType;
        }

        public float GetMaxCarSpeed()
        {
            return 200f;
        }
    }
    
    public class HatchbackCar  : ICar
    {
        public CarType GetCarType()
        {
            return CarType.HatchbackCarType;
        }

        public float GetMaxCarSpeed()
        {
            return 200f;
        }
    }

    public interface ICar
    {
        CarType GetCarType();
        float GetMaxCarSpeed();

    }
    
    public abstract class CarCreater
    {
        public ICar CreateCarFactoryMethod()
        {
            return new SportCar();
        }
    }
    
    /// <summary>
    ///  具体工厂类： 用于创建跑车类
    /// </summary>
    public class SportCreater : CarCreater
    {
        public ICar CreateCar()
        {
            return new SportCar();
        }
    }

    /// <summary>
    ///  具体工厂类： 用于创建越野车类
    /// </summary>
    public class JeepCreater : CarCreater
    {
        public ICar CreateCar()
        {
            return new JeepCar();
        }
    }

    /// <summary>
    ///  具体工厂类： 用于创建两厢车类
    /// </summary>
    public class HatchbackCreater : CarCreater
    {
        public ICar CreateCar()
        {
            return new HatchbackCar();
        }
    }
    
    public class FactoryDesign1
    {
        public static void main(string[] args)
        {
            var test = new FactoryDesign1(new SportCreater());
            Console.WriteLine(test.GetMaxCarSpeed());
        }

        private CarCreater _creater;
        
        public FactoryDesign1(CarCreater creater)
        {
            _creater = creater;
        }

        public float GetMaxCarSpeed()
        {

            var car = _creater.CreateCarFactoryMethod();

            return car.GetMaxCarSpeed();
        }     
    }
    
    

    public interface IGPS
    {
        
    }

    public interface ICarFactory
    {
        ICar CreateCar();
        IGPS CreateGPS();
    }

    public class BeiDouGPS : IGPS
    {
        
    }
    
    public class AmericanGPS : IGPS
    {
        
    }

    public class CarFactory1:ICarFactory
    {
        public ICar CreateCar()
        {
            return new SportCar();
        }

        public IGPS CreateGPS()
        {
            return new BeiDouGPS();
        }
    }
    
    public class FactoryDesign2
    {
        public static void main(string[] args)
        {
            var test = new FactoryDesign2(new CarFactory1());
        }

        private CarFactory1 _creater;
        
        public FactoryDesign2(CarFactory1 creater)
        {
            _creater = creater;
        }

        public float GetMaxCarSpeed()
        {

            var car = _creater.CreateCar();

            return car.GetMaxCarSpeed();
        }

        public void PrintGps()
        {
            var gps = _creater.CreateGPS();
            
        }
    }

    public interface IBuilder
    {
        void buildCar(string data);
        void buildGps(string data);
    }

    public class CarStruct
    {
        public string Type;
        public string Data;
    }

    public class SportCarBuilder : IBuilder
    {
        private ICar _car;
        private IGPS _gps;
        public void buildCar(string data)
        {
            _car = new SportCar();;
        }

        public void buildGps(string data)
        {
            _gps = new BeiDouGPS();
        }

        public ICar GetCar()
        {
            return _car;
        }

        public IGPS GetGps()
        {
            return _gps;
        }
    }
    
    public class CarDirector
    {

        private IBuilder _builder;
        
        public CarDirector(IBuilder builder)
        {
            _builder = builder;
            
        }

        public void Parse(List<CarStruct> structs)
        {
            foreach (CarStruct carStruct in structs)
            {
                Parse(carStruct);
            }
        }

        private void Parse(CarStruct carStruct)
        {
            switch (carStruct.Type)
            {
                case "car":
                    _builder.buildCar(carStruct.Data);
                    break;
                case "GPS":
                    _builder.buildGps(carStruct.Data);
                    break;
                default:
                    break;
            }
        }
    }
    
    public class BuildDesign
    {
        public static void main(string[] args)
        {
            var builder = new SportCarBuilder();
            var director = new CarDirector(builder);
            director.Parse(new List<CarStruct>());
            builder.GetCar();
            builder.GetGps();
        }
    }
    
    public interface IProtoTypeCar:ICar
    {
        IProtoTypeCar Clone();
    }

    public class ProtoSportCar : IProtoTypeCar
    {
        public IProtoTypeCar Clone()
        {
            return new ProtoSportCar();
        }

        public CarType GetCarType()
        {
            return CarType.SportCarType;
        }

        public float GetMaxCarSpeed()
        {
            return 200f;
        }
    }
    
    public class ProtoJeepCar : IProtoTypeCar
    {
        public IProtoTypeCar Clone()
        {
            return new ProtoJeepCar();
        }

        public CarType GetCarType()
        {
            return CarType.SportCarType;
        }

        public float GetMaxCarSpeed()
        {
            return 200f;
        }
    }

    public class Client
    {
        private IProtoTypeCar _car;
        public Client(IProtoTypeCar car)
        {
            _car = car;
        }

        public IProtoTypeCar GetANewCar()
        {
            return _car.Clone();
        }
        
    }

    
    public class PrototypeDesign
    {
        public static void main(string[] args)
        {
            var Client = new Client(new ProtoSportCar());
            var car = Client.GetANewCar();
            car.GetMaxCarSpeed();
        }
    }
}