// main.cpp

#include "DLLPlaylist.h"

Song makeSong(string title, string artist, int duration, int playcount, float rating) {
    Song S;
    S.Title = title;
    S.Artist = artist;
    S.DurationSec = duration;
    S.PlayCount = playcount;
    S.Rating = rating;
    return S;
}

int main() {
    List Playlist;
    Song deletedSong;
    Song updatedSong;
    Song insertedSong;

    cout << "=================================================" << endl;
    cout << "          SIMULASI DOUBLE LINKED LIST            " << endl;
    cout << "=================================================" << endl;
    

    createList(Playlist);
    
    Song s1 = makeSong("Senja di Kota", "Nona Band", 210, 150, 4.2);
    insertLast(Playlist, s1);
    cout << "-> Insert: " << s1.Title << endl;

    Song s2 = makeSong("Langkahmu", "Delta", 185, 320, 4.8);
    insertLast(Playlist, s2);
    cout << "-> Insert: " << s2.Title << endl;
    
    Song s3 = makeSong("Hujan Minggu", "Arka", 240, 90, 3.9);
    insertLast(Playlist, s3);
    cout << "-> Insert: " << s3.Title << endl;

    viewList(Playlist);

    cout << "\n##Delete Last 1x ##" << endl;
    deleteLast(Playlist, deletedSong);
    cout << "Lagu yang dihapus (deleteLast): **" << deletedSong.Title << "**" << endl;

    cout << "\nList setelah deleteLast:" << endl;
    viewList(Playlist);
    
    cout << "\n## Update Node pada Posisi ke-2 ##" << endl;
    updatedSong = makeSong("Pelita", "Luna", 260, 200, 4.5);
    updateAtPosition(Playlist, updatedSong, 2);


    cout << "\n## Tampilkan List setelah Update ##" << endl;
    viewList(Playlist);
   
    cout << "\n## Operasi BEFORE ##" << endl;


    cout << "\n-- insertBefore pada Posisi 2 --" << endl;
    insertedSong = makeSong("Senandung", "Mira", 175, 120, 4.0);
    address pos2 = findNodeAtPosition(Playlist, 2); // Node "Pelita"
    if (pos2 != nullptr) {
        insertBefore(Playlist, pos2, insertedSong);
        cout << "Lagu **" << insertedSong.Title << "** berhasil diinsert sebelum Posisi 2." << endl;
    }
    
    cout << "\nList setelah insertBefore:" << endl;
    viewList(Playlist);

    cout << "\n-- updateBefore pada Posisi 2 --" << endl;
    updatedSong = makeSong("Lagu Lama", "Budi", 190, 100, 3.5);
    updateBefore(Playlist, 2, updatedSong); 
    cout << "\nList setelah updateBefore:" << endl;
    viewList(Playlist);
    
    cout << "\n-- deleteBefore pada Posisi 3 --" << endl;
    address pos3 = findNodeAtPosition(Playlist, 3);
    if (pos3 != nullptr) {
        deleteBefore(Playlist, pos3, deletedSong); 
        cout << "Lagu yang dihapus (deleteBefore): **" << deletedSong.Title << "**" << endl;
    }
    
    cout << "\nList setelah deleteBefore:" << endl;
    viewList(Playlist);
    cout << "\n## Searching berdasarkan PopularityScore ##" << endl;
    float min = 150.0;
    float max = 300.0;
    searchByPopularityRange(Playlist, min, max);

    cout << "\n=================================================" << endl;
    cout << "          SIMULASI SELESAI                       " << endl;
    cout << "=================================================" << endl;

    return 0;
}