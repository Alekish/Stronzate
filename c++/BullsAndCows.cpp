// BULLS AND COWS
// BY ALESSANDRO FELICI!
#include "std_lib_facilities.h"  // libreria standard con alcune aggiunte (scritta da Bjarne Stroustrup)

int main()
{
    try // prova il codice e gestirà poi eventuali eccezzioni (nce fa caso, fai conto che da qui in poi inizia il vero main())
    { 
        int seed;   // seed per il numero casuale
        int again;  // variabile per la ripetizione del gioco (nserve a ncazzo)
        int gameCounter = 1;    // gamecounter, conta quanti giochi hai vinto (parte da 1 ma tanto te lo fa vede alla fine quando hai vinto)
        int bull = 0;   // variabile che conta i bull (numeri nella giusta posizione)
        int cow = 0;    // variabile che conta le cow (numeri che ci sono ma nella posizione sbagliata)

        cout << "Quick, quick, give me a random number (for the seed)!: ";  // ci famo da un seed (potremmo generarlo in altri modi ma STICAZZI)
        cin >> seed;    // input del seed
        seed_randint(seed); //  imposta il seed nella libreria <random> (credo sia) (non serve includerla, basta che includete la libreria che vi passo su github)

        while (true)    // while true, esegue all'infinito finché non c'è un break
        {
            vector<int> bulls(4); // = {5, 1, 5, 9}; // vettore grande 4, ora i tori vengono generati casualmente
            vector<int> guess(bulls.size());       // vettore per salvare le guess (i numeri provati) dell'utente
            vector<int> guessed(bulls.size());      // vettore per salvare le guess azzeccate (i numeri azzeccati) dall'utente

            bull = 0; // RESETTING BULL COUNTER
            cow = 0;  // RESETTING COW COUNTER      Or else the program does not start! (it does not enter the main loop)
                        
            for (int i = 0; i < bulls.size(); i++)      
                bulls[i] = randint(9);          // generiamo per ogni indice del vettore bulls un numero casuale da 0 a 9 (randin(9))

            if(gameCounter == 1)
                cout << "\n\n\n\n- - - Bulls and Cows - - - \n¯\\_(ツ)_/¯\n";       // messaggio di benvenuto standard
            else
                cout << "\n\n#" << gameCounter << " game of:\n- - - Bulls and Cows - - - \n¯\\_(ツ)_/¯\n";      // messaggio di benvenuto se hai già vinto

            while (bull != bulls.size())        // finche i bull (i numeri azzeccati nella giusta posizione) non sono tutti quelli di bulls(il vettore) esegue il while
            {
                bull = 0; // RESETTING BULL COUNTER
                cow = 0;  // RESETTING COW COUNTER

                // CLEARING THE GUESSED POSITIONS SO THAT YOU CAN GUESS AGAIN
                for (int i = 0; i < bulls.size(); i++)
                    guessed[i] = 0; // le desc. in inglese sono quelle che avevo nella vers. precedente, ora aggiungo anche quelle in it. per spiegare bene
                                    // comunque si, pulisco il vettore delle guess dell'utente così che possa re inserire altre guess
                // CHEAT MODE!
                if(again == 3){     // si attiva solo se quando hai vinto almeno una volta hai selezionato la cheat mode (again == 3)
                    cout << "Solution: ";
                    for (int i = 0; i < bulls.size(); i++)
                    {
                    cout << " " <<bulls[i];     // stampa la soluzione (ogni bull del vettore bulls)
                    }
                    cout << "\n";
                }
                // GETTING INPUT FROM USER
                for (int i = 0; i < bulls.size(); i++)
                {
                    cout << "Insert #" << i + 1 << " number: ";     
                    cin >> guess[i];    // carica il vettore con le guess dell'utente
                }
                // GETTING THE BULLS AND EXCLUDING THEM FROM THE POSSIBLE OTHER GUESSES
                for (int i = 0; i < bulls.size(); i++)
                {
                    if (guess[i] == bulls[i] && guessed[i] != -1)   // se la guess dell'utente è nella posizione corretta ed è uguale a quella del vettore bulls (&& non è già stato indovinato (diverso da -1))
                    {
                        bull++; // aggiungi
                        guessed[i] = -1; // MARK NUMBER AS GUESSED  // ho un vettore (guessed), che esclude i numeri già indovinati dall'essere ricontati di nuovo, quando nella posizione i è salvato -1 invece che 0 allora quel numero è già stato indovinato
                    }
                }
                // GETTING THE COWS ON THE REMAINING NOT EXLUDED POSITIONS AND EXCLUDE THEM BY BEING GUESSED AGAIN
                for (int i = 0; i < bulls.size(); i++)  // per ogni input dell'utente
                {
                    for (int j = 0; j < bulls.size(); j++)  // e per ogni numero dentro i bulls
                    {
                        if (guess[i] == bulls[j] && guessed[j] != -1) // se un numero che hai messo è in una posizione j (una qualsiasi), e quella posizione j non è già stata indovinata (&& guessed[j] != -1 (-1 sarebbe già indovinato (aridaje)))
                        {
                            cow++;  // aggiungi una mucca
                            guessed[j] = -1;    // e setta quel numero come "indovinato" (anche se non è propriamente indovinato (è una mucca, non un bull), settarlo come tale impedirà di ricontare di nuovo quella cow, e non la conterà a prescindere se è già stato indovinato come bull)
                            break;  // e smette di scannerizzare per quel numero guess[i] e va al prossimo i (i++ del for annidato)
                        }
                    }
                }
                // CHEKING IF YOU WON OR NOT
                if (bull != bulls.size())   // se il numero di tori è uguale alla grandezza del vettore dei tori da indovinare hai vinto
                    cout << "You got " << bull << " bulls and " << cow << " cows\n";
                else    
                    cout << bull << " BULLS! DAAAANG YOU WIN MATE! GG\n";
            }
            // if you played in cheat mode the game doesn't count!
            if(again != 3)
                gameCounter++;  // ti toglie il gamecounter se hai selezionato la cheatmode prima

            again = 0; // resetting choice
            
            // WANNA PLAY AGAIN?
            while (again != 1 && again != 2 && again != 3)  // piccolo stupido menu in cui puoi selezionare la cheatmode
            {
                cout << "Wanna play another game?\n[1] Yes!\n[2] No!\n[3] Cheat mode!\n";
                cin >> again;
            }
            if (again == 2)
                break;
        }
        cout << "See you again!\n";
        keep_window_open();     // funzione scritta in quella libreria che mo vi posto su github ("std_lib_facilities.h"), che non fa altro che aspettare un input prima di chiudere di botto il programma (tipo quando runni un .exe e si chiude di botto alla fine)
        return 0;
    }
    catch (exception &e)    // blocco catch che gestisce eventuali exception e ne stampa l'errore (non dovrebbe mai succedere, in caso il catch sta qui e aspetta errori e te li mostra)
    {
        cerr << "error: " << e.what() << " ¯\\_(ツ)_/¯ \n";
        keep_window_open(); 
        return 1;   // invece di return 0 ritorniamo alla console di debug un valore anomalo (di solito 0 viene ritornato quando è tutto ok)
    }
    catch (...) // blocco catch che cattura le eccezzioni ignote (non mi è mai successo, ma non si sa mai)
    {
        cerr << "unknown error ¯\\_(ツ)_/¯";
        keep_window_open();
        return 2;
    }
}