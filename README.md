# Library
This repository holds the code for my second project in the Object Oriented Programming with CPP course @ Faculty of Mathematics and Informatics

Във всяка библиотека се съхраняват и предоставят на читатели различни печатни издания като книги, периодични издания (вестници, списания) и комикси. 
Всяка книга се характеризира със следните данни:
автор;
заглавие;
издателство;
жанр - 16 битово цяло число - прочетете по-долу
кратко описание;
библиотечен номер (цяло число);
година на издаване.

Периодичните издания се характеризират със:
заглавие;
периодичност (ежеседмично, ежемесечно, веднъж в годината);
кратко описание;
брой;
библиотечен номер (цяло число);
година на издаване.

Комиксите се характеризират със следните характеристики:
автор;
заглавие;
издателство;
жанр - 16 битово цяло число - прочетете по-долу;
кратко описание;
периодичност (ежеседмично, ежемесечно, веднъж в годината);
брой;
библиотечен номер (цяло число);
година на издаване.

В библиотеката има определен брой екземпляри от всяко печатно издание. Читателите, които са регистрирани в библиотеката, могат да заемат избрани печатни издания за срок от един месец, но не повече от 5 наведнъж.


Жанрът в книгата и комикса трябва да се получи чрез побитово комбиниране на следните четири компонента (до 16 битово цяло число без знак):
	Характеристика - съхранен в младшите 7 бита. Характеристики са например фантастика, трилър, криминална проза и т.н
	Тип - съхранен в следващите 4 бита. Тип е например поезия, проза, драма и т.н.
	Целева аудитория - съхранява се в следващите 4 бита. Целева аудитория е например деца, юноши, възрастни и т.н.
	Контрол по четност - най-старшият бит е контролен бит. Неговата стойност е 0 или 1 така, че броят на всички единични битове (включително този) за жанра да е четно число.
