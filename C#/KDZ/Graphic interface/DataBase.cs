using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Information_keepers;

namespace Graphic_interface
{
    class DataBase
    {
        static public List<string> container = new List<string>();
        static public List<InfKeeper> objcont = new List<InfKeeper>();
        static public InfKeeper fromHumanReadable(string s)//построчно читаем файл
        {
            string[] arr = s.Split(' ');
            Book bookobj; Disk diskobj; FlashCard flashobj;//заполняемые объекты
            if (arr[0] == "Book")
            {
                int curryear = int.Parse(arr[1]);
                int numofpages = int.Parse(arr[2]);
                Book.BindingMaterials current = (Book.BindingMaterials)Enum.
                  Parse(typeof(Book.BindingMaterials), arr[3].ToString());
                bookobj = new Book(arr[0], curryear, numofpages, current);
                return bookobj;
            }
            if (arr[0] == "Disk")
            {
                int curryear = int.Parse(arr[1]);
                double diam = double.Parse(arr[2]);
                Disk.TypeDisk current = (Disk.TypeDisk)Enum.
                  Parse(typeof(Disk.TypeDisk), arr[3].ToString());
                diskobj = new Disk(arr[1], curryear, diam, current);
                return diskobj;
            }
            if (arr[0] == "FlashCard")
            {
                int curryear = int.Parse(arr[1]);
                FlashCard.JackType current = (FlashCard.JackType)Enum.
                  Parse(typeof(FlashCard.JackType), arr[3].ToString());
                FlashCard.TypeMemory typemem = (FlashCard.TypeMemory)Enum.
                  Parse(typeof(FlashCard.TypeMemory), arr[3].ToString());
                flashobj = new FlashCard(arr[0], curryear, typemem, current);
                return flashobj;
            }
            return null;
        }
    }
}