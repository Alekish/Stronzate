//Indici: vengono utilizzati per accedere a elementi in classi e strutture che hanno una losta di valori.
//Un esempio sono la classe delle stringhe, che presentano un indice per ogni carattere:
string stringa = "Ciao";
Console.WriteLine(stringa[0]); //stampa "C"
Console.WriteLine(stringa[1] + "\n"); //stampa "i"


//Ora proviamo ad implementare un indice ad una frase, che ci possa separare le parole di una stringa
Frase parola1 = new Frase();
Console.WriteLine(parola1[2]); //stamperà la parola con indice 2, "verde"
parola1[2] = "Giovanni";       //modifico la parola con indice 2
Console.WriteLine(parola1[2]); //stamperà la parola con indice 2, "Giovanni"    


StaticConstructor Giorgio = new StaticConstructor();
StaticConstructor Giorgio2 = new StaticConstructor(); //Questo non darà alcun risultato poiché lo staticonstractur è gia stato usato
Console.WriteLine(Giorgio.getA());
Giorgio.setA(900000); //Modifico il valore statico di A
Console.WriteLine(Giorgio.getA());


class Frase { //Definisco una classe chiamata "Frase"
    string[] parole = "Il bosco verde parla molto forte".Split(" "); //Il metodo split separa la stringa in base al modo specificato
    //                        in questo caso trova gli spazi tra i caratteri e li usa per separare le parole e metterle in un array
    public string this [int indiceParola] //Definizione di una proprietà
    {
        get { return parole[indiceParola]; }
        set { parole[indiceParola] = value; }
    }
}

//STATIC CONSTRUCTOR, serve per eseguire un inizializzazione UNA SOLA VOLTA
class StaticConstructor{ //Lo static constructor viene eseguito una volta e non una volta per chiamata!!
    static int a; //le variabili devono essere statiche
    static StaticConstructor() { a = 90; Console.WriteLine("Ho inizializzato il tipo"); }
    public int getA() { return a; } //ritorno il valore di a
    public void setA(int b) { a = b; } // modifico il valore di a
}

//ANCHE UNA CLASSE PUO' ESSERE STATICA, E QUESTO COMPORTA CHE ESSA NON PUO' AVERE SOTTOCLASSI E CHE TUTTI I SUOI MEMBRI SIANO STATICI