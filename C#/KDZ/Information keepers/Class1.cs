using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Information_keepers
{
    [Serializable]
    public abstract class InfKeeper//общий класс - Носитель информации
    {
        public InfKeeper(string name, int year)
        {
            this.name = name;
            this.year = year;
        }
        public InfKeeper() : this("Unknown", 0) { }
        protected string name;//название
        protected int year;//год выпуска
        public virtual string Name//свойство доступа к названию предмета
        {
            get { return name; }
            set { name = value; }
        }
        public virtual int Year//свойство доступа к году создания
        {
            get { return year; }
            set { year = value; }
        }
        public abstract string Record(InfKeeper obj);
    }
    [Serializable]
    public class Book : InfKeeper//Первый дочерний класс - Книга
    {
        public Book() : base() { }
        public Book(string name, int year, int numberofpages, BindingMaterials material)
        {
            base.name = name;
            base.year = year;
            this.numberofpages = numberofpages;
            this.material = material;
        }
        public override string Name//свойство доступа к названию предмета
        {
            get { return name; }
            set { name = value; }
        }
        public override int Year//свойство доступа к году создания
        {
            get { return year; }
            set { year = value; }
        }
        private int numberofpages;//количество страниц
        public int NumberOfPages
        {
            get { return numberofpages; }
            set { numberofpages = value; }
        }
        private BindingMaterials material;//материал переплёта
        public BindingMaterials Material
        {
            get { return material; }
            set { material = value; }
        }
        public enum BindingMaterials { Cardboard, Tissue, Paper, Composite, Plastic }
        public override string Record(InfKeeper obj)//запись данных о книге в строку
        {
            string result;
            Book bobj = (Book)obj;
            return result = "Book " + bobj.Name + " " + bobj.Year.ToString() + " "
                + bobj.NumberOfPages.ToString() + " " + bobj.Material.ToString();
        }
    }
    public class Disk : InfKeeper//Второй сыновничий класс - Диск
    {
        public Disk() : base() { }
        public Disk(string name, int year, double diametr, TypeDisk disktype)
        {
            base.name = name;
            base.year = year;
            diskdiameter = diametr;
            this.disktype = disktype;
        }
        public override string Name//свойство доступа к названию предмета
        {
            get { return name; }
            set { name = value; }
        }
        public override int Year//свойство доступа к году создания
        {
            get { return year; }
            set { year = value; }
        }
        private TypeDisk disktype;//тип диска
        public TypeDisk DiskType
        {
            get { return disktype; }
            set { disktype = value; }
        }
        public enum TypeDisk { CD, DVD, Bluray, UDO, UMD };
        private double diskdiameter;
        public double DiskDiameter
        {
            get { return diskdiameter; }
            set { diskdiameter = value; }
        }
        public override string Record(InfKeeper obj)//запись данных о диске в строку
        {
            string result;
            Disk dobj = (Disk)obj;
            return result = "Disk " + dobj.Name + " " + dobj.Year.ToString() + " "
                + dobj.DiskType.ToString() + " " + dobj.DiskDiameter.ToString();
        }
    }
    public class FlashCard : InfKeeper//Третий дочерний класс - Флэш-карта
    {
        public FlashCard() : base() { }
        public FlashCard(string name, int year, TypeMemory type, JackType jack)
        {
            base.name = name;
            base.year = year;
            memorytype = type;
            requiredjack = jack;
        }
        public override string Name//свойство доступа к названию предмета
        {
            get { return name; }
            set { name = value; }
        }
        public override int Year//свойство доступа к году создания
        {
            get { return year; }
            set { year = value; }
        }
        private JackType requiredjack;//требуемый разъем
        public JackType RequiredJack
        {
            get { return requiredjack; }
            set { requiredjack = value; }
        }
        public enum JackType { Mini, Micro, Standart, USB }
        private TypeMemory memorytype;//тип памяти
        public TypeMemory MemoryType
        {
            get { return memorytype; }
            set { memorytype = value; }
        }
        public enum TypeMemory { CF, MMC, SD, MSD, MS }
        public override string Record(InfKeeper obj)//запись данных о диске в строку
        {
            string result;
            FlashCard fobj = (FlashCard)obj;
            return result = "FlashCard " + fobj.Name + " " + fobj.Year.ToString() + " "
                + fobj.RequiredJack.ToString() + " " + fobj.MemoryType.ToString();
        }
    }
}