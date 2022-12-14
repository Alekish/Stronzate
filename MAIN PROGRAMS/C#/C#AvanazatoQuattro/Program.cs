//DOWNCAST E UPCAST

//L'upcasting è un operazione che avviene senza dover specificare l'operazione e si basa sul
//promuovere una variabile o un tipo ad uno più vasto.
//esempio:
int a = 90;
long b = a;     //Upcasting, metodo lecito

//Il downcasting è un operazione che avviene in modo esplicito e si basa sull'opposto dell'upcasting
//retrocede una variabile o un tipo ad un tipo molto meno vasto.
a = (int) b;    //Downcasting, metodo lecito ed esplicito

//AS OPERATOR
//l'operatore as effettua downcast in null se il downcast da effettuare è impossibilitato
string? c = null;
string? d = c as string; //? = nullable
Console.WriteLine(d); //Non stamperà nulla

Aula La1 = new Aula();
Console.WriteLine(La1.punteggio);
Università informatica = new Università();
Console.WriteLine(informatica.punteggio);

//VIRTUAL KEYCODE
public class Università{
    public string facolta = "Informatica";
    public virtual int punteggio => 90; //Il virtual keycode è necessario per eseguire un override. un override può essere eseguito
    //                                    Su una variabile o su un metodo di una classe
}
public class Aula : Università{ //Aula eredita la classe Università
    public string classe = "Classe LA1";
    public override int punteggio => 900; //Override serve per sovrascrivere una variaabile o un metodo virtual, qualsiasi Aula avrà
    //                                      Come punteggio 900 al posto di 90
}

