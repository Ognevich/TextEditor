#include "Renderer.hpp"

void Renderer::RenderBufferWithCursor(Cursor& cursor, TextBuffer& buffer)
{
	std::vector<std::string> lines = buffer.getBufferLines();

    for (int i = 0; i < lines.size(); i++) {
        std::string line = lines[i];
        if (i == cursor.getRows()) {
            int col = cursor.getCols();
            if (col < 0) col = 0;
            if (col > line.size()) col = line.size();
            line.insert(col, "|");
        }
        std::cout << i << "\t|" << " " << line << std::endl;
    }
}
