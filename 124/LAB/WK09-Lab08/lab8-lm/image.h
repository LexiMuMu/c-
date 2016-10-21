struct pixel
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

class image
{
	public:
		image();
		~image();
		void readImage(const char filename[]);
		void scaleImage(int factor);
		void writeImage(const char filename[]);
	private:
		pixel* pixmap;
		int xdim, ydim;
};


