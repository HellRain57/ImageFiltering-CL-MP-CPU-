__constant sampler_t sampler = CLK_NORMALIZED_COORDS_FALSE |  CLK_ADDRESS_CLAMP | CLK_FILTER_NEAREST;  

__kernel void greenFilter(read_only image2d_t src_image, write_only image2d_t dst_image)
{
	uint y = get_global_id(1);
	uint x = get_global_id(0);
	int2 coor = (int2)(x, y);

	uint4 color = read_imageui(src_image, sampler, coor);
	uint colorG = color.y;
	uint4 newColor = (uint4)(0, colorG, 0, 255);
	write_imageui(dst_image, coor, newColor);
}


__kernel void blueFilter(read_only image2d_t src_image, write_only image2d_t dst_image)
{
	uint y = get_global_id(1);
	uint x = get_global_id(0);
	int2 coor = (int2)(x, y);

	uint4 color = read_imageui(src_image, sampler, coor);
	uint colorB = color.z;
	uint4 newColor = (uint4)(0, 0, colorB, 255);
	write_imageui(dst_image, coor, newColor);
}


__kernel void redFilter(read_only image2d_t src_image, write_only image2d_t dst_image)
{
	uint y = get_global_id(1);
	uint x = get_global_id(0);
	int2 coor = (int2)(x, y);

	uint4 color = read_imageui(src_image, sampler, coor);
	uint colorR = color.x;
	uint4 newColor = (uint4)(colorR, 0, 0, 255);
	write_imageui(dst_image, coor, newColor);
}


__kernel void smoothingFilter(read_only image2d_t src_image, write_only image2d_t dst_image)
{
	uint y = get_global_id(1)+1;
	uint x = get_global_id(0)+1;
	uint height = get_global_size(1);

	float tempR[9], tempG[9], tempB[9];
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			int2 coor = (int2)(x+i, y+j);
			uint4 color = read_imageui(src_image, sampler, coor);
			tempR[(i + 1) * 3 + j + 1] = color.x;
			tempG[(i + 1) * 3 + j + 1] = color.y;
			tempB[(i + 1) * 3 + j + 1] = color.z;
		}
	}

	int tempValueR = tempR[0];
	int tempValueG = tempG[0];
	int tempValueB = tempB[0];
	for (int i = 1; i < 9; i++) {
		tempValueR += tempR[i];
		tempValueG += tempG[i];
		tempValueB += tempB[i];
	}
	tempValueR = tempValueR / 9;
	tempValueG = tempValueG / 9;
	tempValueB = tempValueB / 9;

	tempValueR = (tempValueR < 0) ? 0 : (tempValueR > 255) ? 255 : tempValueR;
	tempValueG = (tempValueG < 0) ? 0 : (tempValueG > 255) ? 255 : tempValueG;
	tempValueB = (tempValueB < 0) ? 0 : (tempValueB > 255) ? 255 : tempValueB;

	int2 coorCenter = (int2)(x, y);
	uint4 newColor = (uint4)(tempValueR, tempValueG, tempValueB, 255);
	write_imageui(dst_image, coorCenter, newColor);
}



__kernel void clarityFilter(read_only image2d_t src_image, write_only image2d_t dst_image)
{
	uint y = get_global_id(1) + 1;
	uint x = get_global_id(0) + 1;
	uint height = get_global_size(1);

	float tempR[9], tempG[9], tempB[9];
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			int2 coor = (int2)(x + i, y + j);
			uint4 color = read_imageui(src_image, sampler, coor);
			tempR[(i + 1) * 3 + j + 1] = color.x;
			tempG[(i + 1) * 3 + j + 1] = color.y;
			tempB[(i + 1) * 3 + j + 1] = color.z;
		}
	}

	int tempValueR = (-1) * tempR[0];
	int tempValueG = (-1) * tempG[0];
	int tempValueB = (-1) * tempB[0];
	for (int i = 1; i < 9; i++) {
		if (i == 4)
		{
			tempValueR += 9 * tempR[4];
			tempValueG += 9 * tempG[4];
			tempValueB += 9 * tempB[4];
		}
		else
		{
			tempValueR += (-1) * tempR[i];
			tempValueG += (-1) * tempG[i];
			tempValueB += (-1) * tempB[i];
		}
	}

	tempValueR = (tempValueR < 0) ? 0 : (tempValueR > 255) ? 255 : tempValueR;
	tempValueG = (tempValueG < 0) ? 0 : (tempValueG > 255) ? 255 : tempValueG;
	tempValueB = (tempValueB < 0) ? 0 : (tempValueB > 255) ? 255 : tempValueB;

	int2 coorCenter = (int2)(x, y);
	uint4 newColor = (uint4)(tempValueR, tempValueG, tempValueB, 255);
	write_imageui(dst_image, coorCenter, newColor);
}



__kernel void medianFilter(read_only image2d_t src_image, write_only image2d_t dst_image)
{
	uint y = get_global_id(1) + 1;
	uint x = get_global_id(0) + 1;
	uint height = get_global_size(1);

	float tempR[9], tempG[9], tempB[9];
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			int2 coor = (int2)(x + i, y + j);
			uint4 color = read_imageui(src_image, sampler, coor);
			tempR[(i + 1) * 3 + j + 1] = color.x;
			tempG[(i + 1) * 3 + j + 1] = color.y;
			tempB[(i + 1) * 3 + j + 1] = color.z;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < (8 - i); j++) {
			if ((tempR[j] > tempR[j + 1])) {

				float copy = tempR[j];
				tempR[j] = tempR[j + 1];
				tempR[j + 1] = copy;
			}

			if ((tempG[j] > tempG[j + 1])) {

				float copy = tempG[j];
				tempG[j] = tempG[j + 1];
				tempG[j + 1] = copy;
			}

			if ((tempB[j] > tempB[j + 1])) {

				float copy = tempB[j];
				tempB[j] = tempB[j + 1];
				tempB[j + 1] = copy;
			}
		}
	}


	int2 coorCenter = (int2)(x, y);
	uint4 newColor = (uint4)(tempR[4], tempG[4], tempB[4], 255);
	write_imageui(dst_image, coorCenter, newColor);
}