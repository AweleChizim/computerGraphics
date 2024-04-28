#include "renderer3D.h"
#include <SDL.h>
#include <iostream>

renderer3D::renderer3D(SDL_Window* _window, SDL_Renderer* renderer, std::vector<Point3D>& _points, std::vector<Edge>& _edges)
{
	SDL_GetWindowSize(_window, &WindowSizeX, &WindowSizeY);
	SDL_render = renderer;
	points = _points;
	edges = _edges;
}

void renderer3D::render()
{
	auto time1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration(0);

	SDL_SetRenderDrawColor(SDL_render, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(SDL_render);
	SDL_SetRenderDrawColor(SDL_render, 255, 192, 203, SDL_ALPHA_OPAQUE);

	/*if ((sx <= 1.5) && (sx >= 0.1))
	{
		sx += -1 * DeltaTime;
		sy += -1 * DeltaTime;
	}
	else if (sx <= 0.1)
	{
		sx = 1.5;
		sy = 1.5;

	}*/
	/*if ((sx <= 1.5) && (sx >= -1.5))
	{
		sx += -1 * DeltaTime;
		sy += -1 * DeltaTime;
	}
	else if (sx <= -1.5)
	{
		sx = 1.5;
		sy = 1.5;
	}*/
	if (sx == 1.5)
	{
		sx = 0.5;
		sy = 0.5;
		SDL_Delay(500);
	}
	else if (sx == 0.5)
	{
		sx = 1.5;
		sy = 1.5;
		SDL_Delay(500);
	}
	
	for (auto& edge : edges) {
		Point3D rotatedPointStart = scaling(points[edge.start]);
		Point3D rotatedPointEnd = scaling(points[edge.end]);
		Point2D start = projection(rotatedPointStart);
		Point2D end = projection(rotatedPointEnd);

		SDL_RenderDrawLine(SDL_render, start.x, start.y, end.x, end.y);
	}

	SDL_RenderPresent(SDL_render);

	auto time2 = std::chrono::high_resolution_clock::now();
	duration = time2 - time1;
	DeltaTime = duration.count();
	time1 = time2;
}

Point2D renderer3D::projection(Point3D point)
{
	return Point2D{ WindowSizeX / 2 + (point.x * FL) / (FL + point.z) * 100, WindowSizeY / 2 + (point.y * FL) / (FL + point.z) * 100 };
}

Point3D renderer3D::scaling(Point3D point)
{
	Point3D scaledPoint;
	scaledPoint.x = point.x * sx;
	scaledPoint.y = point.y * sy;
	scaledPoint.z = point.z;
	return scaledPoint;
}

