#include "WebCreator.hpp"

int main() {
	WebCreator page("Dog Adoption");
	page.ConvertToHtml("sample_style.style", "sample_page.page", "output.html");

	return 0;
}