//      "C# AVANZATO" E' UNA CATEGORIA AVANZATA DEL C#, SE NON SAI MOLTO SUL LINGUAGGIO SEGUI LE LEZIONI
using System;


class Avanzato{

// Read-Only Proprieties:
    int readOnly = 10;
    public int ReadOnly{
        get { return (readOnly * 2); } //la variabile ha solo metodo get e riporta il valore di "readOnly"
    } 

//Write-Only Proprieties:
    int wrtiteOnly = 20;
    public int WriteOnly{
        set { wrtiteOnly = wrtiteOnly*value;} //la variabile ha solo metodo get e modifica il valore di "writeOnly"
    }

// Expression-Bodied Proprieties: Le proprietà possono essere scritte anche in modo differente, una freccia può rimpiazzare tutte
// Le parentesi che utilizziamo normalmente nella dichiarazione di una proprietà e i "return" keywords
    int prova = 90;
    public int expressionBodied{
        get => prova * 20;
        set => prova = prova * value;
    }

// Automatic proprieties: La proprietà automatica permette all'utente di accedere alla variabile in maniera diretta senza dover
// Specificare get, set e le relative variabili e soprattutto senza il keycode "value"
public int automaticProprieties{get; set;}  //La proprietà automatica non usa variabili esterne
//                                            Di fatti usa il valore di se stessa.



    // _____________ MAIN ______________ \\
public static void Main(string[] args)
{
    Avanzato alekish = new Avanzato();
    Console.WriteLine("La variabile in Read-Only è: " + alekish.ReadOnly);
    alekish.expressionBodied = 90;
    Console.WriteLine("La variabile in Expression Bodied" + alekish.expressionBodied);
    alekish.automaticProprieties = 900;
    alekish.automaticProprieties += 800;
    Console.WriteLine("La variabile di automaticProprieties è: " + alekish.automaticProprieties);
}
}