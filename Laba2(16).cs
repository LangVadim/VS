using System;

class Program {
  static void Main() {
    Console.WriteLine("Введите скобку: ");
    char bracket = Console.ReadKey().KeyChar;
    switch (bracket) {
      case '(':
      case ')':
        Console.WriteLine(" Круглая скобка.");
        break;
      case '{':
      case '}':
        Console.WriteLine("Фигурная скобка. Действия зависят от контекста.");
        break;
      default:
        Console.WriteLine("Неизвестный вид скобки.");
        break;
    }
  }
}