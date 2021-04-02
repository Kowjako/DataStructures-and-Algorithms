# SDiZO —  Projekt Nr. 1 🏁
Projekt przedstawia realizację podstawowych struktur danych takich jak  
1️⃣ Tablica dynamiczna  
2️⃣ Lista dwukierunkiowa  
3️⃣ Kopiec binarny Max-Type  
4️⃣ Drzewo BST   
### Dla każdej struktury realizowane następne funkcje 💡
- Operacje dodawnia na początku, w środek oraz koniec
- Operacje usuwania na początku, w środku oraz końca 
- Operacje wyszukiwania elementu
### Dodatkowo dla drzewa BST zostały napisane 🔧
- Funkcje rotacji w lewo oraz prawo względem dowolnego wierzchołka
- Równoważenie drzewa Algorytmem DSW (``Day-Stout-Warren``)
### Badanie złożoności czasowej dla realizowanych funkcji 📝
W gąłęzi ***Project*** można znaleźć raport gdzie przedstawiono załeżności czasowe dla każdej struktury w zależności od wykonywanej operacji
### Pomiar czasu ⌚
Pomiar czasu był dokonany za pomocą **QueryPerformanceCounter()**
#### Przykład realizacji funkcji pomiaru czasu:
```c++
long long int read_QPC()
{
  LARGE_INTEGER count;
  QueryPerformanceCounter(&count);
  return((long long int)count.QuadPart);
}
```
#### Dokonanie pomiaru czasu: 
```c++
void main(void)
{
   long long int frequency, start, elapsed;
   QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
   start = read_QPC();
   Sleep(1000); 
   elapsed = read_QPC() - start;
   cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed)/frequency << endl;
} 
```
### Równiez w repozytorium można znaleźć 🔎
1️⃣ Realizacja stosu i kolejki za pomocą tablicy dynamicznej  
2️⃣ Realizacja stosu i kolejki za pomocą listy  
3️⃣ Realizcja listy jednokierunkowej  
4️⃣ Metoda Floyda do tworzenia kopca, ale dla projektu ten folder nie jest potrzebny
