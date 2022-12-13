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
string c = null;
string d = c as string;
Console.WriteLine(d); //Non stamperà nulla

