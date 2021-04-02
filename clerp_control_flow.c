void	set_color(int val, int *r, int *g, int *b)
{
	int result;

	result = 0;
	if (val < 40)
		result = clerp(0x33FF00, 0x00FF00, val - 0, 40);
	else if (val < 200)
		result = clerp(0x00FF00, 0x00FFFF, val - 40, 160);
	else if (val < 400)
		result = clerp(0x00FFFF, 0x6633FF, val - 200, 200);
	else if (val < 800)
		result = clerp(0x6633FF, 0x000000, val - 400, 400);
	ctoRGB(result, r, g, b);
}
