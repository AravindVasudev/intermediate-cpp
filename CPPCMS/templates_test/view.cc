#line 1 "view.tmpl"
#include "content.h" 
#line 2 "view.tmpl"
namespace view {
	#line 3 "view.tmpl"
	struct  message :public cppcms::base_view
	#line 3 "view.tmpl"
	{
	#line 3 "view.tmpl"
		content::message &content;
	#line 3 "view.tmpl"
		message(std::ostream &_s,content::message &_content): cppcms::base_view(_s),content(_content),_domain_id(0)
	#line 3 "view.tmpl"
		{
	#line 3 "view.tmpl"
			_domain_id=booster::locale::ios_info::get(_s).domain_id();
	#line 3 "view.tmpl"
		}
		#line 4 "view.tmpl"
		virtual void render() {
		#line 4 "view.tmpl"
			cppcms::translation_domain_scope _trs(out(),_domain_id);

			#line 7 "view.tmpl"
			out()<<"\n"
				"<html>\n"
				"    <body>\n"
				"        <h1>";
			#line 7 "view.tmpl"
			out()<<cppcms::filters::escape(content.text);
			#line 10 "view.tmpl"
			out()<<" World!</h1>\n"
				"    </body>\n"
				"</html>\n"
				"";
		#line 10 "view.tmpl"
		} // end of template render
	#line 11 "view.tmpl"
	private:
	#line 11 "view.tmpl"
		int _domain_id;
	#line 11 "view.tmpl"
	}; // end of class message
#line 12 "view.tmpl"
} // end of namespace view
#line 2 "view.tmpl"
namespace view {
#line 12 "view.tmpl"
} // end of namespace view
#line 13 "view.tmpl"
namespace {
#line 13 "view.tmpl"
 cppcms::views::generator my_generator; 
#line 13 "view.tmpl"
 struct loader { 
#line 13 "view.tmpl"
  loader() { 
#line 13 "view.tmpl"
   my_generator.name("view");
#line 13 "view.tmpl"
   my_generator.add_view<view::message,content::message>("message",true);
#line 13 "view.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 13 "view.tmpl"
 }
#line 13 "view.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 13 "view.tmpl"
} a_loader;
#line 13 "view.tmpl"
} // anon 
