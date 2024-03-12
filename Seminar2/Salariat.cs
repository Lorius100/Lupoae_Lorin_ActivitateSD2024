using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace S2___PAW
{
    internal class Salariat
    {
        string nume;
        int no;
        float so;

        public Salariat() { nume = "Anonim"; no = 0; so = 1; }
        public string Nume
        {
            get { return nume; }
            set { nume = value; }
        }

        public float Salariul => no * so;

        public int Numar_ore
        {
            get => no;
            set
            {
                if (value < 0) throw new Exception("ERR Numar ore NEGATIV!");
                no = value;
            }
        }

        public float Salariul_orar
        {
            get => so;
            set => so = value;
        }

        public override string ToString() => $"Salariatul {Nume} are salariul {Salariul}";
    }

    class Firma
    {
        List<Salariat> ls;
        string denf;
        public Firma(string fn)
        {
            ls = new List<Salariat>();
            denf = fn;
        }

        public void adaugaSalariat(Salariat sal)
        {
            ls.Add(sal);
        }

        public string denumireFirma
        {
            get => denf;
            set => denf = value;
        }

        public Salariat this[int k]
        {
            get
            {
                if (k < 0 || k >= ls.Count) throw new IndexOutOfRangeException("ERR: Pozitie invalida!");
                return ls[k];
            }
            set => ls[k] = value;
        }
    }
}
