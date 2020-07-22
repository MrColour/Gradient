void	set_color(int val, int *r, int *g, int *b)
{
	int result;

	result = 0;
	if (val < 10)
		result = clerp(0x33FF00, 0x00FF00, val - 0, 10);
	else if (val < 50)
		result = clerp(0x00FF00, 0x00FFFF, val - 10, 40);
	else if (val < 100)
		result = clerp(0x00FFFF, 0x6633FF, val - 50, 50);
	else if (val < 200)
		result = clerp(0x6633FF, 0x000000, val - 100, 100);
	ctoRGB(result, r, g, b);
}
