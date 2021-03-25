# SDiZO —  Projekt Nr. 1 🏁
Projekt przestawia realizację podstawowych struktur danych takich jak  
1️⃣ Tablica dynamiczna  
2️⃣ Lista jednokierunkowa  
3️⃣ Lista dwukierunkiowa  
4️⃣ Kopiec binarny Max-Type  
5️⃣ Drzewo BST   
### Dla każdej struktury realizowane następne funkcje 💡
- Operacje dodawnia na początku, w środek oraz koniec
- Operacje usuwania na początku, w środku oraz końca 
- Operacje wyszukiwania elementu
### Dodatkowo dla drzewa BST zostały napisane 🔧
- Funkcje rotacji w lewo oraz prawo względem dowolnego wierzchołka
- Równoważenie drzewa Algorytmem DSW (``Day-Stout-Warren``)
### Badanie złożoności czasowej dla realizowanych funkcji 📝
W gąłęzi ***raport*** można znaleźć raport gdzie przedstawiono załeżności czasowe dla każdej struktury w zależności od wykonywanej operacji
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
