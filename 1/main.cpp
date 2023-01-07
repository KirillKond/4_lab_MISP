/**
* @file modAlphaCipher.h
* @author Кондратьев К.М.
* @version 1.0.0
* @brief Заголовочный файл для модуля modAlphaCipher
* @date 07.01.2023
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <vector>
#include <string>
#include <map>
#include <codecvt>
#include <locale>
/* @class modAlphaCipher
 * @date 07.01.2023
 * @file modAlphaCipher.h
 * @brief Шифрование методом Гронсфельда
 * @detalies Для зашифрования и расшифрования сообщения предназначены методы encrypt и decrypt. Текст на обработку передается в качестве параметра.
 * @warnings Реализация только для русского языка!
 */
class modAlphaCipher
{
private:
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";  //Русский алфавит заглавных букв по порядку
    std::map <wchar_t,int> alphaNum;   //ассоциативный массив "номер по символу"
    std::vector <int> key;          //ключ
    std::vector<int> convert(const std::wstring& ws);//преобразование строка-вектор
    std::wstring convert(const std::vector<int>& v);//преобразование вектор-строка
    /** @brief Метод класса, проверяющий текст на валидность
     * @param [in] s Текст на русском языке
     * @return result
     */
    std::wstring getValidKey(const std::wstring & ws);//метод, который будет проверять ключ на валидности и переводить в нем символы в верхний регистр
    std::wstring getValidOpenText(const std::wstring & ws);
    /** @brief Метод класса, проверяющий расшифрованный текст на валидность
     * @param [in] s Зашифрованный текст на русском языке
     * @return result
     */
    std::wstring getValidCipherText(const std::wstring & ws);
    /** @brief Метод класса, проверяющий ключ на валидность
     * @param [in] s Ключ
     * @return result
     */
public:
    modAlphaCipher()=delete;//запретим конструктор без параметров
    /** @brief Конструктор для создания объекта, хранящего в себе ключ шифрования
     * @param [in] text Открытый текст на русском языке
     * @warnings Текст не должен быть пустой строкой и не должен содержать пробелы. В тексте могут содержаться знаки препинания и цифры.
     */
    modAlphaCipher(const std::wstring& wskey);  //конструктор для установки ключа
    /** @brief Зашифрование
    * @param [in] text Открытый текст на русском языке
    * @warnings Текст не должен быть пустой строкой и не должен содержать пробелы. В тексте могут содержаться знаки препинания и цифры.
    * @return result Зашифрованный текст
    */
    std::wstring encrypt(const std::wstring& open_text);  //зашифрование
    /** @brief Зашифрование
     * @param [in] text Зашифрованный текст на русском языке
     * @warnings Текст не должен быть пустой строкой и не должен содержать пробелы. В тексте могут содержаться знаки препинания и цифры.
     * @return result Зашифрованный текст
     */
    std::wstring decrypt(const std::wstring& cipher_text);//расшифрование
};
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg): //класс-исключение cipher_error как производный от класса std::invalid_argument.
        std::invalid_argument(what_arg) {}
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}
};
