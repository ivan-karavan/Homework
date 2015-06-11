using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Information_keepers;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Xml.Serialization;

//пространство имён, содержащее форму и базу данных
namespace Graphic_interface
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            comboBox1.DataSource = Enum.GetValues(typeof(Book.BindingMaterials)).//вывод в combobox1
                Cast<Book.BindingMaterials>().
                Select(p => new
                { Name = Enum.GetName(typeof(Book.BindingMaterials), p), Value = (int)p }).ToList();
            comboBox1.DisplayMember = "Name";
            comboBox1.ValueMember = "Name";
            comboBox2.DataSource = Enum.GetValues(typeof(Disk.TypeDisk)).//вывод в combobox2
                Cast<Disk.TypeDisk>().
                Select(p => new { Name = Enum.GetName(typeof(Disk.TypeDisk), p), Value = (int)p }).ToList();
            comboBox2.DisplayMember = "Name";
            comboBox2.ValueMember = "Name";
            comboBox3.DataSource = Enum.GetValues(typeof(FlashCard.JackType)).//вывод в combobox3
                Cast<FlashCard.JackType>().
                Select(p => new { Name = Enum.GetName(typeof(FlashCard.JackType), p), Value = (int)p }).ToList();
            comboBox3.DisplayMember = "Name";
            comboBox3.ValueMember = "Name";
            comboBox4.DataSource = Enum.GetValues(typeof(FlashCard.TypeMemory)).//вывод в combobox4
                Cast<FlashCard.TypeMemory>().
                Select(p => new { Name = Enum.GetName(typeof(FlashCard.TypeMemory), p), Value = (int)p }).ToList();
            comboBox4.DisplayMember = "Name";
            comboBox4.ValueMember = "Name";
        }
        XmlSerializer xmlfile = new XmlSerializer(typeof(List<string>));//сериализатор
        StreamReader sr;//ссылка на входной поток
        StreamWriter sw;//выходной поток
        private int i = 0;//будет счётчиком строк                
        private void Form1_Load(object sender, EventArgs e)
        {
            dataGridView1.ColumnCount = 5;
            dataGridView1.Columns[0].HeaderText = "Information keeper";
            dataGridView1.Columns[1].HeaderText = "Name";
            dataGridView1.Columns[2].HeaderText = "Year";
            dataGridView1.Columns[3].HeaderText = "Property1";
            dataGridView1.Columns[4].HeaderText = "Property2";
        }
        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e) {}
        private void saveFileDialog1_FileOk(object sender, CancelEventArgs e){}
        private void openFileDialog1_FileOk(object sender, CancelEventArgs e){}
        private void toolStripMenuItem1_Click(object sender, EventArgs e) {}
        private void toolStripMenuItem2_Click(object sender, EventArgs e) {}
        private void toolStripMenuItem3_Click(object sender, EventArgs e) {}
        private void toolStripButton1_Click(object sender, EventArgs e)//добавление новой строки
        {
            if (radioButton1.Checked == false & radioButton2.Checked == false & radioButton3.Checked == false)
            { MessageBox.Show("Select the type of object to be added"); return; }
            if (radioButton1.Checked == true)//если выбрана книга
            {
                //временные переменные
                int temp4=0,temp2=0;
                Book.BindingMaterials selected = Book.BindingMaterials.Cardboard;
                try { temp2 = int.Parse(textBox2.Text);
                      temp4 = int.Parse(textBox4.Text);
                      selected = (Book.BindingMaterials)Enum.
                          Parse(typeof(Book.BindingMaterials), comboBox1.SelectedValue.ToString());}
                catch { MessageBox.Show("Year must be a number and Number of pages must be a positive number");}
                if (textBox3.Text == "") { textBox3.Text = "unknown"; }//на случай пустого текста в имени
                //теперь имя с пробелами разделяем нижним подчёркиванием
                string[] arrname = textBox3.Text.Split(' ');
                string name = arrname[0];
                for (int k = 1; k < arrname.Length; k++)
                    name = name + '_' + arrname[k];
                //создание нового объекта по собранным данным
                Book obj = new Book(name, temp4, temp2, selected);
                string line = obj.Record(obj);
                DataBase.objcont.Add(obj);
                DataBase.container.Add(line);
                string[] arr = line.Split(' ');
                //теперь добавим строку в datagridview
                dataGridView1.RowCount++;
                i++;
                //заполнение cтроки в datagridview
                if (i == 0)
                    for (int k = 0; k < 5; k++)
                        dataGridView1[k, i].Value = arr[k];
                else
                    for (int k = 0; k < 5; k++)
                        dataGridView1[k, i - 1].Value = arr[k];
                radioButton1.Checked = false;
                textBox3.Text = textBox4.Text = textBox2.Text = ""; comboBox1.SelectedValue = "";
            }
            if (radioButton2.Checked == true)//если выбран диск
            {
                int temp4 = 0; double temp5 = 0;//временные переменные
                Disk.TypeDisk selected = Disk.TypeDisk.CD;
                try
                {
                    temp5 = double.Parse(textBox5.Text);
                    temp4 = int.Parse(textBox4.Text);
                    selected = (Disk.TypeDisk)Enum.
                    Parse(typeof(Disk.TypeDisk), comboBox2.SelectedValue.ToString());
                }
                catch { MessageBox.Show("Year must be a number, Diameter must be a positive number and Disk type must be chosen"); }
                if (textBox3.Text == "") { textBox3.Text = "unknown"; }//на случай пустого текста в имени
                //теперь имя с пробелами разделяем нижним подчёркиванием
                string[] arrname = textBox3.Text.Split(' ');
                string name = arrname[0];
                for (int k = 1; k < arrname.Length; k++)
                    name = name + '_' + arrname[k];
                //создание нового объекта по собранным данным
                Disk obj = new Disk(name, temp4, temp5, selected);
                string line = obj.Record(obj);
                DataBase.objcont.Add(obj);
                DataBase.container.Add(line);
                string[] arr = line.Split(' ');
                //теперь добавим строку в datagridview
                dataGridView1.RowCount++;
                i++;
                //заполнение cтроки в datagridview
                if (i == 0)
                    for (int k = 0; k < 5; k++)
                        dataGridView1[k, i].Value = arr[k];
                else
                    for (int k = 0; k < 5; k++)
                        dataGridView1[k, i - 1].Value = arr[k];
                //очищаем после добавления строки
                radioButton2.Checked = false;
                textBox3.Text = textBox4.Text = textBox5.Text = ""; comboBox2.SelectedValue = "";
            }
            if (radioButton3.Checked == true)//если выбрана флеш карта
            {
                //временные переменные
                int temp4 = 0; FlashCard.JackType selectedjack = FlashCard.JackType.USB; FlashCard.TypeMemory selectedmemory = FlashCard.TypeMemory.CF;
                try
                {
                    temp4 = int.Parse(textBox4.Text);
                    selectedjack = (FlashCard.JackType)Enum.
                    Parse(typeof(FlashCard.JackType), comboBox3.SelectedValue.ToString());
                    selectedmemory = (FlashCard.TypeMemory)Enum.
                    Parse(typeof(FlashCard.TypeMemory), comboBox4.SelectedValue.ToString());
                }
                catch { MessageBox.Show("Year must be a number"); }               
                if (textBox3.Text == "") { textBox3.Text = "unknown"; }//на случай пустого текста в имени
                //теперь имя с пробелами разделяем нижним подчёркиванием
                string[] arrname = textBox3.Text.Split(' ');
                string name = arrname[0];
                for (int k = 1; k < arrname.Length; k++)
                    name = name + '_' + arrname[k];
                //создание нового объекта по собранным данным
                FlashCard obj = new FlashCard(name, temp4, selectedmemory, selectedjack);
                string line = obj.Record(obj);
                DataBase.container.Add(line);
                DataBase.objcont.Add(obj);                
                string[] arr = line.Split(' ');
                //теперь добавим строку в datagridview
                dataGridView1.RowCount++;
                i++;
                if (i == 0)
                    for (int k = 0; k < 5; k++)
                        dataGridView1[k, i].Value = arr[k];
                else
                    for (int k = 0; k < 5; k++)
                        dataGridView1[k, i - 1].Value = arr[k];
                radioButton2.Checked = false;
                textBox3.Text = textBox4.Text = ""; comboBox3.SelectedValue = comboBox4.SelectedValue = "";
            }
        }
        public string toHumanReadable()//для записи человекочитаемого текста
        {
            // Установка начальной папки
            saveFileDialog1.InitialDirectory = "C:";
            // Задание возможных расширений для файла
            saveFileDialog1.Filter = "txt files (*.txt)|*.txt|All files|*.*";
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                // Код по сохранению
                string fileName = saveFileDialog1.FileName;
                File.WriteAllLines(fileName, DataBase.container);
                return fileName;//возвращает имя файла
            }
            else return null;
        }
        private void toolStripButton2_Click(object sender, EventArgs e)//удаление строки
        {
            try 
            {
                int index = dataGridView1.CurrentRow.Index;
                dataGridView1.Rows.Remove(dataGridView1.CurrentRow);            
                DataBase.container.RemoveAt(index);
            }
            catch 
            {
                for (int k = 0; k < 5; k++)
                    dataGridView1[k, dataGridView1.CurrentRow.Index].Value = "";
            }
        }
        private void toolStripMenuItem4_Click(object sender, EventArgs e)//help
        { MessageBox.Show("Помоги себе сам!"); }
        private void toolStripMenuItem5_Click(object sender, EventArgs e)//сохранение текстового файла
        {
            // Установка начальной папки
            saveFileDialog1.InitialDirectory = "C:";
            // Задание возможных расширений для файла
            saveFileDialog1.Filter = "txt files (*.txt)|*.txt|All files|*.*";
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                 //Код по сохранению
                try
                {
                    string fileName = saveFileDialog1.FileName;
                    sw = new StreamWriter(fileName);
                    foreach (InfKeeper a in DataBase.objcont)
                        sw.Write(a);
                    sw.Close();
                    //File.WriteAllLines(fileName, DataBase.container);
                }
                catch { MessageBox.Show("Процесс не может получить доступ к файлу, так как этот файл используется другим процессом."); }
            }
        }
        private void toolStripMenuItem6_Click(object sender, EventArgs e)//сериализация
        {
            // Установка начальной папки
            saveFileDialog1.InitialDirectory = "C:";
            // Задание возможных расширений для файла
            saveFileDialog1.Filter = "Serialized (*.xml)|*.xml";
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                // Код по сохранению
                //try
                //{
                    string fileName = saveFileDialog1.FileName;
                    sw = new StreamWriter(fileName);
                    xmlfile.Serialize(sw, DataBase.objcont);
                    sw.Flush();
                    //xmlfile.Serialize(sw, DataBase.container);
                    sw.Close();
                //}
                //catch { MessageBox.Show("Процесс не может получить доступ к файлу, так как этот файл используется другим процессом."); }
            }
        }
        private void toolStripMenuItem7_Click(object sender, EventArgs e)//открытие текстового файла
        {
            DataBase.container.Clear();//если загружаем файл не в первый раз
            openFileDialog1.InitialDirectory = "C:";// Установка начальной папки
            openFileDialog1.Filter = "txt files (*.txt)|*.txt";// Задание возможных расширений для файла
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                string fileName = openFileDialog1.FileName;
                sr = new StreamReader(fileName);
                string input = null;
                while ((input = sr.ReadLine()) != null)//заполняем коллекцию
                { DataBase.container.Add(input); }
                this.i = 0;//номер строки
                foreach (string s in DataBase.container)//выводим на формочку
                {
                    string[] arr = s.Split(' ');
                    dataGridView1.ColumnCount = 5;
                    dataGridView1.RowCount = DataBase.container.Count + 1;
                    for (int j = 0; j < 5; j++)
                    {
                        dataGridView1[j, i].Value = arr[j];
                    }
                    ++i;
                }
            }
        }
        private void toolStripMenuItem8_Click(object sender, EventArgs e)//десериализация
        {
            DataBase.container.Clear();//если загружаем файл не в первый раз
            openFileDialog1.InitialDirectory = "C:";// Установка начальной папки
            openFileDialog1.Filter = "Serialized (*.xml)|*.xml";// Задание возможных расширений для файла
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                string fileName = openFileDialog1.FileName;
                sr = new StreamReader(fileName);
                DataBase.container = (List<string>)xmlfile.Deserialize(sr);
                //заполняем коллекцию
                string input = null;
                while ((input = sr.ReadLine()) != null)
                { DataBase.container.Add(input); }
                this.i = 0;//номер строки
                foreach (string s in DataBase.container)//выводим на формочку
                {
                    string[] arr = s.Split(' ');
                    dataGridView1.ColumnCount = 5;
                    dataGridView1.RowCount = DataBase.container.Count + 1;
                    for (int j = 0; j < 5; j++)
                    {
                        dataGridView1[j, i].Value = arr[j];
                    }
                    ++i;
                }
            }
        }
        private void toolStripMenuItem9_Click(object sender, EventArgs e)//добавление в файл
        {
            // Установка начальной папки
            saveFileDialog1.InitialDirectory = "C:";
            // Задание возможных расширений для файла
            saveFileDialog1.Filter = "txt files (*.txt)|*.txt|All files|*.*";
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                // Код по сохранению
                try
                {
                    string fileName = saveFileDialog1.FileName;
                    sw = new StreamWriter(fileName + DataBase.container, true);
                }
                catch { MessageBox.Show("Процесс не может получить доступ к файлу, так как этот файл используется другим процессом."); }
            }
        }      
    }
}