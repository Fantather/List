#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

int main() {
    std::cout << "=== SinglyLinkedList Demo ===\n";
    SinglyLinkedList<int> sList;

    // Add elements
    sList.push_front(10);
    sList.push_tail(30);
    sList.push_by_index(20, 1);    // Insert 20 at index 1
    std::cout << "After inserting 10, 20, 30: ";
    sList.show();                  // Expected output: 10 20 30
    std::cout << "\n";

    // Search and replace
    size_t idx = sList.Search(20);
    if (idx != SinglyLinkedList<int>::NULL_) {
        std::cout << "Value 20 found at position " << idx << "\n";
    }
    int replaced = sList.Replacement(20, 25);
    std::cout << "Replaced " << replaced << " occurrence(s) of 20->25: ";
    sList.show();
    std::cout << "\n";

    // Reverse
    sList.Reverse();
    std::cout << "After reversing: ";
    sList.show();
    std::cout << "\n";

    // Remove from front and tail
    sList.pop_front();
    sList.pop_tail();
    std::cout << "After pop_front and pop_tail: ";
    sList.show();
    std::cout << "\n";

    // Clear all
    sList.DeleteAll();
    std::cout << "After DeleteAll, list is "
        << (sList.empty() ? "empty\n" : "not empty\n");

    std::cout << "\n=== DoublyLinkedList Demo ===\n";
    DoublyLinkedList<int> dList;

    // Add elements
    dList.AddToHead(100);
    dList.AddToTail(300);
    dList.AddToHead(50);
    std::cout << "After inserting 50(head), 100, 300(tail): ";
    dList.Show();                  // Expected output: 50 100 300
    std::cout << "\n";

    // Search and replace
    auto opt = dList.Search(100);
    if (opt) {
        std::cout << "Value 100 found at position " << *opt << "\n";
    }
    int count = dList.Replace(100, 150);
    std::cout << "Replaced " << count << " occurrence(s) of 100->150: ";
    dList.Show();
    std::cout << "\n";

    // Reverse
    dList.Reverse();
    std::cout << "After reversing: ";
    dList.Show();
    std::cout << "\n";

    // Remove from head and tail
    dList.DeleteFromHead();
    dList.DeleteFromTail();
    std::cout << "After DeleteFromHead and DeleteFromTail: ";
    dList.Show();
    std::cout << "\n";

    // Clear all
    dList.DeleteAll();
    std::cout << "After DeleteAll, list should be empty\n";
}


//Задание 1
//Создайте шаблонный класс двусвязного списка для работы с целыми значениями.Требуется создать реализации для типичных операций над элементами :
//1.AddToHead – добавление элемента в голову.
//2.AddToTail – добавление элемента в хвост.
//3.DeleteFromHead – удаление элемента из головы.
//4.DeleteFromTail – удаление элемента из хвоста.
//5.DeleteAll – удаление всех элементов.
//6.Show – отображение всех элементов списка на экран.
//
//Задание 2
//Добавить в класс из задания 1 следующие функции : вставка элемента в заданную позицию, удаление элемента по заданной позиции,
//поиск заданного элемента(функция возвращает позицию найденного элемента в случае успеха или NULL в случае неудачи),
//поиск и замена заданного элемента(функция возвращает количество замененных элементов в случае успеха или - 1 в случае неудачи),
//переворот списка.

// ===========

//Задание 1
//Создайте шаблонный класс двусвязного списка для работы с целыми значениями.Требуется создать реализации для типичных операций над элементами :
//1.AddToHead – добавление элемента в голову.
//2.AddToTail – добавление элемента в хвост.
//3.DeleteFromHead – удаление элемента из головы.
//4.DeleteFromTail – удаление элемента из хвоста.
//5.DeleteAll – удаление всех элементов.
//6.Show – отображение всех элементов списка на экран.

// Задание 2
// Добавить в класс из задания 1 следующие функции :
// вставка элемента в заданную позицию
// удаление элемента по заданной позиции
// поиск заданного элемента (функция возвращает позицию найденного элемента в случае успеха или NULL в случае неудачи)
// поиск и замена заданного элемента(функция возвращает количество замененных элементов в случае успеха или - 1 в случае неудачи)
// переворот списка.