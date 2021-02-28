
#include "math_util.h"
#include <cmath>

// circle vs circle
bool isCircleCollided(float ax, float ay, float ar,
	float bx, float by, float br)
{
	const float dx = bx - ax;
	const float dy = by - ay;
	const float d = sqrt(dx * dx + dy * dy);

	if (ar + br < d)
	{
		return false;
	}

	return true;
}

// box vs box
bool isBoxCollided(float ax, float ay, float awidth, float aheight,
	float bx, float by, float bwidth, float bheight)
{
	bool xAxis = false;
	bool yAxis = false;

	// x axis
	if (ax + awidth > bx && bx + bwidth > ax)
		xAxis = true;

	// y axis
	if (ay + aheight > by && by + bheight > ay)
		yAxis = true;

	if (xAxis && yAxis)
		return true;

	return false;
}

bool isPointInCircle(float cx, float cy, float cr, float px, float py)
{
	float dx = px - cx;
	float dy = py - cy;

	float len = sqrt(dx * dx + dy * dy);

	if (len > cr)
		return false;

	return true;
}

// circle vs box
bool isCircleVsBoxCollided(float ax, float ay, float ar,
	float bx, float by, float bw, float bh)
{

	float halfW = bw / 2;
	float halfH = bh / 2;

	if ((bx <= ax && ax <= bx + bw) || ((by <= ay) && (ay <= by + bh)))
	{
		//반지름 만큼 사각형을 확장
		float n_bleft = bx - ar;
		float n_btop = by - ar;
		float n_bright = bx + bw + ar;
		float n_bbottom = by + bh + ar;

		if ((n_bleft <= ax && ax <= n_bright) && (n_btop <= ay && ay <= n_bbottom))
		{
			return true;
		}
	}
	else
	{
		//사각형의 꼭짓점이 원안에 있나 파악
		if (isPointInCircle(ax, ay, ar, bx, by))
			return true;
		else if (isPointInCircle(ax, ay, ar, bx + bw, by))
			return true;
		else if (isPointInCircle(ax, ay, ar, bx, by + bh))
			return true;
		else if (isPointInCircle(ax, ay, ar, bx + bw, by + bh))
			return true;
	}
	return false;
}