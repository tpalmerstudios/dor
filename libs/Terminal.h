#include <iomanip>
#include <sys/ioctl.h>
#include <unistd.h>

class Terminal
{
				enum ANSI :  int { ESC = 27 };
		private:
				int termHeight, termWidth;

		public:
				/*
				 * Creates a Terminal class with dimensions of the current screen
				 */
				Terminal ()
				{
						this->setSize ();
				}
				/*
				 * Creates a Terminal class with custom dimensions
				 */
				Terminal (int x, int y)
				{
						termHeight = y;
						termWidth = x;
				}
				/*
				 * Returns the height in lines of a Terminal
				 */
				int getHeight ()
				{
						return termHeight;
				}
				/*
				 * Returns the width in lines of a Terminal
				 */
				int getWidth ()
				{
						return termWidth;
				}
				/*
				 * Sets the termHeight variable based on system calls
				 */
				void setSize ()
				{
						struct winsize size;
						ioctl (STDOUT_FILENO, TIOCGWINSZ, &size);
						termHeight = size.ws_row;
						termWidth = size.ws_col;
				}
				/*
				 * Clears the Terminal via ANSI escape codes
				 */
				static std::string clearscr ()
				{
						std::stringstream ss;
						ss << static_cast<char>(ESC) << "[H" << static_cast<char>(ESC) << "[2J";
						return ss.str ();
				}
				/*
				 * Go to Terminal position via ANSI escape codes
				 * @param x position the cursor rows
				 * @param y position the cursor columns
				 */
				static std::string goLoc (int x, int y)
				{
						std::stringstream ss;
						ss << static_cast<char>(ESC) << "[" << x << ";" << y << "H";
						return ss.str ();
				}
				/*
				 * Underline Terminal output with ANSI escape codes
				 */
				static std::string underline ()
				{
						std::stringstream ss;
						ss << static_cast<char>(ESC) << "[4m";
						return ss.str ();
				}
				/*
				 * Remove underline from Terminal output with ANSI escape codes
				 */
				static std::string underlineOff ()
				{
						std::stringstream ss;
						ss << static_cast<char>(ESC) << "[24m";
						return ss.str ();
				}
				/*
				 * Emphasize Terminal output with ANSI escape codes
				 */
				static std::string bold ()
				{
						std::stringstream ss;
						ss << static_cast<char>(ESC) << "[1m";
						return ss.str ();
				}
				/*
				 * Remove Emphasis from Terminal output via ANSI escape codes
				 */
				static std::string boldOff ()
				{
						std::stringstream ss;
						ss << static_cast<char>(ESC) << "[21m";
						return ss.str ();
				}
				/*
				 * Saves the cursor position in a Terminal with ANSI escape codes
				 */
				static std::string save ()
				{
						std::stringstream ss;
						ss << static_cast<char>(ESC) << "[s";
						return ss.str ();
				}
				/*
				 * Restores the cursor position in a Terminal with ANSI escape codes
				 */
				static std::string restore ()
				{
						std::stringstream ss;
						ss << static_cast<char>(ESC) << "[u";
						return ss.str ();
				}
				/*
				 * Moves the cursor in Terminal up with ANSI escape codes
				 * @param y columns to move the cursor up
				 */
				static std::string up (int y)
				{
						std::stringstream ss;
						ss << static_cast<char>(ESC) << "[" << y << "A";
						return ss.str ();
				}
				/*
				 * Moves the cursor in Terminal down with ANSI escape codes
				 * @param y columns to move the cursor down
				 */
				static std::string down (int y)
				{
						std::stringstream ss;
						ss << static_cast<char>(ESC) << "[" << y << "B";
						return ss.str ();
				}
				/*
				 * Moves the cursor in Terminal right with ANSI escape codes
				 * @param x columns to move the cursor right
				 */
				static std::string right (int x)
				{
						std::stringstream ss;
						ss << static_cast<char>(ESC) << "[" << x << "C";
						return ss.str ();
				}
				/*
				 * Moves the cursor in Terminal left with ANSI escape codes
				 * @param x columns to move the cursor left
				 */
				static std::string left (int x)
				{
						std::stringstream ss;
						ss << static_cast<char>(ESC) << "[" << x << "D";
						return ss.str ();
				}
				/*
				 * Color the Terminal output based on ANSI escape codes
				 * @param colorbg an ANSI color code between 40-47
				 * @param colorfg an ANSI color code between 30-37
				 */
				static std::string color (int colorbg, int colorfg)
				{
						std::stringstream ss;
						ss << static_cast<char>(ESC) << "[" << colorbg << ";" << colorfg << "m";
						return ss.str ();
				}
				/*
				 * Reset to default Terminal output based on ANSI escape codes
				 */
				static std::string reset ()
				{
						std::stringstream ss;
						ss << static_cast<char>(ESC) << "[0m";
						return ss.str ();
				}
};
