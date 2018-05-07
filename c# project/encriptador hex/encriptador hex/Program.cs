using System;
using System.IO;
using System.Text;

namespace encriptador_hex
{
    class Program
    {
        static void Main(string[] args)
        {
            Mensaje men = new Mensaje();
            string txt;
            Console.WriteLine("Encriptador hexadecimal 1.0\nEscribe por favor el mensaje que deseas encriptar");
            txt = Console.ReadLine();
            men.Men(txt);
        }
    }
    class Mensaje
    {
        public void Men(string men)
        {
            //se convierte men a una cadena de bytes
            byte[] txt = Encoding.ASCII.GetBytes(men);
            //creo una variable llamada fw y fr para con esa usar StreamWriter y SteamReader
            var fw = new StreamWriter(File.OpenWrite("mensaje.txt"));
            fw.WriteLine(men);
            fw.Close();
            ///experimento para convertir string a byte de byte a hex de hex a string
            ///con StringBuilder hago la variable hex para pasar los bytes de txt a hex despues utilizo foreach
            ///para poder hacer el ciclo e ir concatenando lo convertido en la variable hex
            StringBuilder hex = new StringBuilder(txt.Length * 2);
            foreach (int i in txt)
            {
                hex.AppendFormat("{0:x2} ", i);
            }
            fw = new StreamWriter(File.OpenWrite("encriptado.txt"));
            fw.WriteLine(hex.ToString());
            fw.Close();

        }
    }
}
