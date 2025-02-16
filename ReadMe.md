### Код к заданию: 
<details> 

        #include <fstream>

        class Printable
        {
        public:
            virtual ~Printable() = default;

            virtual std::string printAsHTML() const = 0;
            virtual std::string printAsText() const = 0;
            virtual std::string printAsJSON() const = 0;
        };

        class Data : public Printable
        {
        public:
            enum class Format
            {
                kText,
                kHTML,
                kJSON
            };

            Data(std::string data, Format format)
                : data_(std::move(data)), format_(format) {}

            std::string printAsHTML() const override
            {
                if (format_ != Format::kHTML) {
                    throw std::runtime_error("Invalid format!");
                }
                return "<html>" + data_ + "<html/>";
            }
            std::string printAsText() const override
            {
                if (format_ != Format::kText) {
                    throw std::runtime_error("Invalid format!");
                }
                return data_;
            }
            std::string printAsJSON() const override
            {
                if (format_ != Format::kJSON) {
                    throw std::runtime_error("Invalid format!");
                }
                return "{ \"data\": \"" + data_ + "\"}";
            }

        private:
            std::string data_;
            Format format_;
        };

        void saveTo(std::ofstream &file, const Printable& printable, Data::Format format)
        {
            switch (format)
            {
            case Data::Format::kText:
                file << printable.printAsText();
                break;
            case Data::Format::kJSON:
                file << printable.printAsJSON();
                break;
            case Data::Format::kHTML:
                file << printable.printAsHTML();
                break;
            }
        }

        void saveToAsHTML(std::ofstream &file, const Printable& printable) {
            saveTo(file, printable, Data::Format::kHTML);
        }

        void saveToAsJSON(std::ofstream &file, const Printable& printable) {
            saveTo(file, printable, Data::Format::kJSON);
        }

        void saveToAsText(std::ofstream &file, const Printable& printable) {
            saveTo(file, printable, Data::Format::kText);
        }
</details>

# Задание 1

В приведённом выше коде есть нарушения некоторых принципов SOLID.
Ваша задача найти и перечислить нарушенные принципы и указать, в чём именно состоит нарушение.

## Выявленные нарушения и ошибки:
* ### Принцип подстановки Барбары Лисков (Liskov Substitution Principle, LSP):

Нарушение заключается в том, что класс Data не может быть корректно подставлен вместо базового класса Printable во всех случаях. Например, если у объекта Data формат kText, то вызов метода printAsHTML() выбросит исключение. Это нарушает принцип LSP, так как подкласс не должен изменять поведение базового класса.

* ### Принцип открытости/закрытости (Open/Closed Principle, OCP):

Класс Data не закрыт для изменений. Если потребуется добавить новый формат, придётся изменять код класса Data, добавляя новый метод и изменяя существующие. Это нарушает принцип OCP, который гласит, что классы должны быть открыты для расширения, но закрыты для изменений.

* ### Принцип разделения интерфейса (Interface Segregation Principle, ISP):

Интерфейс Printable содержит слишком много методов, которые не всегда будут использоваться. Например, если классу нужно поддерживать только текстовый формат, он всё равно должен реализовывать методы printAsHTML() и printAsJSON(). Это нарушает принцип ISP, который рекомендует создавать узкоспециализированные интерфейсы, а не общие.

* ## Дополнительные ошибки:
    * #### Синтаксические ошибки: 
    В коде есть несколько синтаксических ошибок, таких как отсутствие точек с запятой, неправильные имена типов (например, stdstring вместо std::string), и неправильные имена констант (например, FormatkHTML вместо Format::kHTML).

    * #### Логика форматирования: 
    Логика форматирования данных (например, добавление тегов HTML) находится внутри класса Data, что делает его менее гибким и нарушает принцип единственной ответственности (Single Responsibility Principle, SRP).

# Задание 2

Нужно переписать код так, чтобы он соответствовал принципам SOLID. Не бойтесь переименовывать сущности, добавлять новые или удалять старые.

В финальной версии должны сохраниться:

функции для сохранения данных в разных форматах,
логика по форматированию данных.
Подсказки
Функция saveTo не должна ничего знать о формате данных.

Попробуйте разделить интерфейс Printable на несколько более специализированных интерфейсов.

Класс Data могут наследовать несколько потомков в зависимости от формата данных.

## Описане внесенных изменений

### Разделение интерфейса:
Интерфейс Printable был разделён на три отдельных интерфейса:
* HTMLPrintable 
* TextPrintable 
* JSONPrintable

 Теперь классы могут реализовывать только те интерфейсы, которые им действительно нужны.

### Принцип открытости/закрытости:
    Теперь, если потребуется добавить новый формат данных, можно просто создать новый класс, реализующий соответствующий интерфейс, без изменения существующего кода.

### Принцип подстановки Барбары Лисков: 
    Каждый класс (HTMLData, TextData, JSONData) корректно реализует соответствующий интерфейс и может быть использован в любом месте, где ожидается этот интерфейс.

### Устранение синтаксических ошибок:
    Исправлены синтаксические ошибки, такие как неправильные имена типов и констант.

### Логика форматирования:
    Логика форматирования данных теперь находится в соответствующих классах, что делает код более гибким и соответствующим принципу единственной ответственности.

разнесение кода по разным файлам имеет смысл, особенно если программа будет расширяться. Это улучшит читаемость, поддерживаемость и модульность кода. Разделение на разные файлы позволяет:

* Упростить навигацию по коду: Каждый файл будет отвечать за определённую функциональность, что упростит поиск и понимание кода.

* Упростить тестирование: Модули можно тестировать независимо друг от друга.

* Упростить расширение: Добавление новых форматов данных или новых функций работы с файлами будет происходить в отдельных файлах, не затрагивая остальной код.

* Соблюдение принципа единственной ответственности (SRP): Каждый файл будет отвечать за свою часть функциональности.

Так же следует отметить, что дробление 1 фаил = 1 класс не всегда способствует простоте программы, и удобству ее чтения и редактирования в будущем.