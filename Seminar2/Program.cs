using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.SqlServer.Server;

namespace S2___PAW
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Firma firma1 = new Firma("Firma 1");
            firma1.adaugaSalariat(new Salariat() { Nume = "Mihai", Numar_ore = 5, Salariul_orar = 3.5F });
            firma1.adaugaSalariat(new Salariat() { Nume = "Alex", Numar_ore = 7, Salariul_orar = 7.9F });
            firma1.adaugaSalariat(new Salariat() { Nume = "Dan", Numar_ore = 4, Salariul_orar = 5.7F });

            try
            {
                firma1[1].Nume = "Alexandru";
                Console.WriteLine(firma1[1]);
            }
            catch (IndexOutOfRangeException iex)
            {
                Console.WriteLine(iex.Message);
            }
        }

    }
}