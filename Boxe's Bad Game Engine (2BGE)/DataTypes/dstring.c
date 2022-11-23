#include "dstring.h"
#include "basic_num_func.h"

DString bool_to_string(DBool value)
{
	DString* str;
	str = malloc(sizeof(DString*));
	if (str == NULL)
	{
		free(str);
		return bool_to_string(value);
	}

	if (value) 
		*str = make_string("true"); 
	else 
		*str = make_string("false");

	return *str;
}

DString int_to_string(long long value)
{
	DString* str;
	int i;

	str = malloc(sizeof(DString*));
	if (str == NULL) 
	{
		free(str);
		return int_to_string(value);
	}

	str->size = get_number_size(value);
	str->text = malloc(str->size + 1);
	if (str->text == NULL)
	{
		string_free(str);
		return int_to_string(value);
	}

	i = 0;
	if (value < 0)
		str->text[0] = '-', i++;
	while (value)
	{
		str->text[str->size - i - 1] = 48 + value % 10;
		value /= 10;
		i++;
	}
	str->text[i] = '\0';

	return *str;
}

DString float_to_string(long double value)
{
	DString* str, * str1;
	long long intDecimalVal;
	int intValue;

	{
		float copy = value;
		long long i = 1;
		
		intValue = (int)value;
		intDecimalVal = intValue;

		while (value != intDecimalVal)
		{
			value *= 10;
			i *= 10;
			intDecimalVal = 1LL * value;
		}

		intDecimalVal -= intValue * i;
		value = copy;
	}

	str = malloc(sizeof(DString*));
	if (str == NULL) 
	{
		free(str);
		return float_to_string(value);
	}

	str1 = malloc(sizeof(DString*));
	if (str1 == NULL)
	{
		free(str);
		free(str1);
		return float_to_string(value);
	}

	*str = int_to_string(intValue);
	*str = string_append(str->text, ".");
	*str1 = int_to_string(intDecimalVal);
	*str = string_append(str->text, str1->text);

	return *str;
}

DString make_string(const char* text)
{
	if (text == NULL) return make_string("NULL");
	size_t size;
	DString* str;

	str = malloc(sizeof(DString*));
	size = 0;

	while (text[size] != '\0')
		size++;
	if (str == NULL)
	{
		free(str);
		return make_string(text);
	}

	str->text = text;
	str->size = size;

	return *str;
}

DString string_append(const char* to_append, const char* string)
{
	if (to_append == NULL || string == NULL)
		return make_string("NULL");

	int i, size;
	DString* str;
	str = malloc(sizeof(DString*));

	if (str == NULL)
	{
		free(str);
		return string_append(to_append, string);
	}

	size = 0;
	for (i = 0; to_append[i] != '\0'; i++);
	size += i;
	for (i = 0; string[i] != '\0'; i++);

	str->text = malloc(size + i);
	str->size = size + i + 1;
	if (str->text == NULL)
	{
		string_free(str);
		return string_append(to_append, string);
	}

	for(i = 0; to_append[i] != '\0'; i++)
		str->text[i] = to_append[i];

	for (i = 0; string[i] != '\0'; i++)
		str->text[size + i] = string[i];
	str->text[size + i] = '\0';

	return *str;
}

void string_free(DString* str)
{
	free(str->text);
	free(str);
}

const widech* char_to_wide(DString string)
{
	widech* wideCs;
	wideCs = malloc(string.size);
	if (wideCs == NULL)
	{
		free(wideCs);
		return char_to_wide(string);
	}
	for (int i = 0; i < string.size; i++)
		wideCs[i] = string.text[i];
	return wideCs;
}