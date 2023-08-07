typed_Elements = {};
page_elements = {};

let addHeader = (name, id) => {
	typed_Elements[name] = new Typed(id, {
		strings: [],
		typeSpeed: 40,
		backSpeed: 10,
		fadeOut: true,
		backDelay: 1000,
        showCursor: false,
	});
	page_elements[name] = document.querySelector(id);

	page_elements[name].addEventListener("mouseenter", function () {
        typed_Elements[name].start();
	});
	page_elements[name].addEventListener("mouseleave", function () {
        typed_Elements[name].reset();
	});
}

setTimeout(() => {
    addHeader("Home", "#nav_home");
    addHeader("Projects", "#nav_projects");
    addHeader("Resources", "#nav_resources");
    addHeader("Downloads", "#nav_downloads");
    addHeader("About", "#nav_about");
}, 500);

/**
 * Home - Index Page
 * Tutorials/Resources - Written articles
 * Projects - Source Code
 * Downloads - PDF Notes
 * About - Personal Info
 */
