//Eredità delle classi :D e polimorfismo
namespace simone{ 
internal class Program
{
    private static void Main(string[] args)
    {

        Banana saverio = new Banana (90, 110);
        Mela simone = new Mela (90, 110);
        Console.WriteLine("Saverio e simo hanno " + saverio.banane + " banane e " +  simone.mele +  " mele");
        Stampa(simone); //Accedo al valore tramite Simone di classe Mela.   Polimorfismo Line: 44
    }


//Definiamo le classi e la loro eredità ARGOMENTO 1
public class Cesto         //definiamo una classe di oggetti chiamata cesto:
{
    public int numeroFrutta;
}
public class Banana : Cesto        //La classe Banana erediterà la classe Cesto, può usare le sue variabili liberamente
{
    public int banane;
    public Banana (int a, int b){         //costruttore
        numeroFrutta = numeroFrutta + a;
        banane = banane + b;
    }
}
public class Mela : Cesto       //La classe mela erediterà la classe Cesto, può usare le sue variabili liberamente
{
    public int mele;
    public Mela (int a, int b) {        //costruttore
        numeroFrutta = numeroFrutta + a;
        mele = mele + b;
    }
}



//         ________________SEPARATORE_________________         \\


//ARGOMENTO 2: Polimorfismo
//dato che i riferimenti di classe sono polimorfici, una variabile di tipo x può riferirsi ad un oggetto presente in una
//nella classe base di x stesso, essendo la classe base parte integrante della sottoclasse x.
//Ad esempio usando le classi Mela, Banana e Cesto il seguente codice è lecito:
public static void Stampa(Cesto cesto)
{
    Console.WriteLine(cesto.numeroFrutta); //Posso accedervi anche da un oggetto di Mela o Banana
}
//Il contrario invece è impossibile, infatti una classe base non può accedere ai valori delle sue sottoclassi poiché non ne fa
//parte in maniera diretta. Nell'esempio precedente se al posto di "Cesto" ci fosse stato "Mela" un oggettto di classe "Cesto"
//non avrebbe potuto accedere al metodo ed avrebbe prodotto un Compile-Time error
}
}