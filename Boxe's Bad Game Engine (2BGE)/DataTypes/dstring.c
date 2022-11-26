#include "dstring.h"
#include "dvector2D.h"
#include "../Core/basic_num_func.h"
#include "../Core/core.h"

DString bool_to_string(DBool value)
{
	DString* str;
	if (!MALLOC(str, sizeof(DString*)))
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

	if (!MALLOC(str, sizeof(DString*)))
	{
		free(str);
		return int_to_string(value);
	}

	str->size = get_number_size(value);
	if (!MALLOC(str->text, str->size + 1))
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

DString decimal_to_string(float value)
{
	DString* str, * str1;
	long int intDecimalVal;
	int intValue;

	intValue = (int)value;
	if (intValue == value)
	{
		return int_to_string(value);
	}

	{
		float copy = value;
		long int i = 1;
		
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

	if (!MALLOC(str, sizeof(DString*)))
	{
		free(str);
		return decimal_to_string(value);
	}

	
	if (!MALLOC(str1, sizeof(DString*)))
	{
		free(str);
		free(str1);
		return decimal_to_string(value);
	}

	*str = int_to_string(intValue);
	*str = string_append(str->text, ".");
	*str1 = int_to_string(intDecimalVal);
	*str = string_append(str->text, str1->text);

	return *str;
}

DString vector2D_to_string(DVector2D vector)
{
	DString* str_x, * str_y;
	if (!MALLOC(str_x, sizeof(DString*)))
	{
		string_free(str_x);
		return vector2D_to_string(vector);
	}
	if (!MALLOC(str_y, sizeof(DString*)))
	{
		string_free(str_x);
		string_free(str_y);
		return vector2D_to_string(vector);
	}

	*str_x = decimal_to_string(vector.x);
	*str_x = string_append("(", str_x->text);
	*str_x = string_append(str_x->text, ",");
	*str_y = decimal_to_string(vector.y);
	*str_x = string_append(str_x->text, str_y->text);
	*str_x = string_append(str_x->text, ")");

	return *str_x;
}

DString make_string(const char* text)
{
	if (text == NULL) return make_string("NULL");
	size_t size;
	DString* str;

	size = 0;

	while (text[size] != '\0')
		size++;
	if (!MALLOC(str, sizeof(DString*)))
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

	if (!MALLOC(str, sizeof(DString*)))
	{
		free(str);
		return string_append(to_append, string);
	}

	size = 0;
	for (i = 0; to_append[i] != '\0'; i++);
	size += i;
	for (i = 0; string[i] != '\0'; i++);
	
	str->size = size + i;
	if (!MALLOC(str->text, str->size + 1))
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
	free(str);
}

const widech* char_to_wide(DString string)
{
	widech* wideCs;
	if (!MALLOC(wideCs, string.size))
	{
		free(wideCs);
		return char_to_wide(string);
	}
	for (int i = 0; i < string.size; i++)
		wideCs[i] = string.text[i];
	return wideCs;
}