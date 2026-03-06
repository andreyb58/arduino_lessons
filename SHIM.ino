// Проект 3 — демонстрация ШИМ
int d = 5;
void setup()
{
// настроить контакт 3, управляющий светодиодом и поддерживающий ШИМ,
// на работу в режиме цифрового выхода
pinMode(3, OUTPUT);
}
void loop()
{
for ( int a = 0 ; a < 256 ; a++ )
{
analogWrite(3, a);
delay(d);
}
for ( int a = 255 ; a >= 0 ; a-- )
{
analogWrite(3, a);
delay(d);
}
delay(200);
}
