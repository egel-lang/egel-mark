#include <egel/runtime.hpp>
#include <egel/ffi.hpp>

#include <string.h>

#include <cmark.h>

// stubs
UnicodeString to_uni(const char* cc) {
    return UnicodeString::fromUTF8(StringPiece(cc));
}

char* from_uni(const UnicodeString& s) {
    const int STRING_MAX_SIZE = 10000000; // XXX: i hate constants
    auto len = s.extract(0, STRING_MAX_SIZE, nullptr, (uint32_t) 0);
    auto buffer = new char[len+1];
    s.extract(0, STRING_MAX_SIZE, buffer, len+1);
    return buffer;
}

int u_strlen(const UnicodeString& s) {
    auto cc = from_uni(s);
    auto r  = strlen(cc);
    delete[] cc;
    return r;
}

extern "C" std::vector<UnicodeString> egel_imports() {
    return std::vector<UnicodeString>();
}

extern "C" std::vector<VMObjectPtr> egel_exports(VM* vm) {
    std::vector<VMObjectPtr> oo;

    // convenience
    oo.push_back(ffi1<vm_int_t, vm_text_t>(vm, "CMark", "cmark_strlen",
                [](vm_text_t s){return (vm_int_t) u_strlen(s);}).clone());
    oo.push_back(ffi1<vm_bool_t, vm_ptr_t>(vm, "CMark", "cmark_isnull",
                [](vm_ptr_t p){return (vm_bool_t) ( p == nullptr) ;}).clone());

    /* enums and constants */

    // node types
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_node", []() { return (vm_int_t) CMARK_NODE_NONE;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_document", []() { return (vm_int_t) CMARK_NODE_DOCUMENT;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_block_quote", []() { return (vm_int_t) CMARK_NODE_BLOCK_QUOTE;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_list", []() { return (vm_int_t) CMARK_NODE_LIST;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_item", []() { return (vm_int_t) CMARK_NODE_ITEM;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_code_block", []() { return (vm_int_t) CMARK_NODE_CODE_BLOCK;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_html_block", []() { return (vm_int_t) CMARK_NODE_HTML_BLOCK;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_custom_block", []() { return (vm_int_t) CMARK_NODE_CUSTOM_BLOCK;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_paragraph", []() { return (vm_int_t) CMARK_NODE_PARAGRAPH;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_heading", []() { return (vm_int_t) CMARK_NODE_HEADING;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_thematic_break", []() { return (vm_int_t) CMARK_NODE_THEMATIC_BREAK;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_first_block", []() { return (vm_int_t) CMARK_NODE_FIRST_BLOCK;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_last_block", []() { return (vm_int_t) CMARK_NODE_LAST_BLOCK;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_text", []() { return (vm_int_t) CMARK_NODE_TEXT;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_softbreak", []() { return (vm_int_t) CMARK_NODE_SOFTBREAK;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_linebreak", []() { return (vm_int_t) CMARK_NODE_LINEBREAK;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_code", []() { return (vm_int_t) CMARK_NODE_CODE;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_html_inline", []() { return (vm_int_t) CMARK_NODE_HTML_INLINE;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_custom_inline", []() { return (vm_int_t) CMARK_NODE_CUSTOM_INLINE;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_emph", []() { return (vm_int_t) CMARK_NODE_EMPH;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_strong", []() { return (vm_int_t) CMARK_NODE_STRONG;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_link", []() { return (vm_int_t) CMARK_NODE_LINK;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_image", []() { return (vm_int_t) CMARK_NODE_IMAGE;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_first_inline", []() { return (vm_int_t) CMARK_NODE_FIRST_INLINE;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_node_last_inline", []() { return (vm_int_t) CMARK_NODE_LAST_INLINE;}).clone());

    // list types
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_no_list", []() { return (vm_int_t) CMARK_NO_LIST;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_bullet_list", []() { return (vm_int_t) CMARK_BULLET_LIST;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_ordered_list", []() { return (vm_int_t) CMARK_ORDERED_LIST;}).clone());

    // delim types
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_no_delim", []() { return (vm_int_t) CMARK_NO_DELIM;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_period_delim", []() { return (vm_int_t) CMARK_PERIOD_DELIM;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_paren_delim", []() { return (vm_int_t) CMARK_PAREN_DELIM;}).clone());

    // options
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_opt_default", []() { return (vm_int_t) CMARK_OPT_DEFAULT;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_opt_sourcepos", []() { return (vm_int_t) CMARK_OPT_SOURCEPOS;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_opt_hardbreaks", []() { return (vm_int_t) CMARK_OPT_HARDBREAKS;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_opt_safe", []() { return (vm_int_t) CMARK_OPT_SAFE;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_opt_nobreaks", []() { return (vm_int_t) CMARK_OPT_NOBREAKS;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_opt_normalize", []() { return (vm_int_t) CMARK_OPT_NORMALIZE;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_opt_validate_utf8", []() { return (vm_int_t) CMARK_OPT_VALIDATE_UTF8;}).clone());
    oo.push_back(ffi0<vm_int_t>(vm, "CMark", "cmark_opt_smart", []() { return (vm_int_t) CMARK_OPT_SMART;}).clone());

    /* combinators */

    // node construction
    oo.push_back(ffi1<vm_ptr_t, vm_int_t>(vm, "CMark", "cmark_node_new",
                [](vm_int_t n){return (vm_ptr_t) cmark_node_new( (cmark_node_type) n);}).clone());
    oo.push_back(ffi1<vm_int_t, vm_ptr_t>(vm, "CMark", "cmark_node_free",
                [](vm_ptr_t p){cmark_node_free( (cmark_node*) p); return (vm_int_t) 0;}).clone()); // return a dummy for now

    // parsing
    oo.push_back(ffi3<vm_ptr_t, vm_text_t, vm_int_t, vm_int_t>(vm, "CMark", "cmark_parse_document",
                [](vm_text_t s, vm_int_t n0, vm_int_t n1){auto cc = from_uni(s); auto r = cmark_parse_document( cc, n0,n1); delete[] cc; return (vm_ptr_t) r;}).clone());
    // rendering
    oo.push_back(ffi2<vm_text_t, vm_ptr_t, vm_int_t>(vm, "CMark", "cmark_render_html",
                [](vm_ptr_t p, vm_int_t n){return to_uni(cmark_render_html( (cmark_node*) p,n));}).clone());
    oo.push_back(ffi2<vm_text_t, vm_ptr_t, vm_int_t>(vm, "CMark", "cmark_render_xml",
                [](vm_ptr_t p, vm_int_t n){return to_uni(cmark_render_xml( (cmark_node*) p,n));}).clone());
    oo.push_back(ffi3<vm_text_t, vm_ptr_t, vm_int_t, vm_int_t>(vm, "CMark", "cmark_render_man",
                [](vm_ptr_t p, vm_int_t n0, vm_int_t n1){return to_uni(cmark_render_man( (cmark_node*) p,n0,n1));}).clone());
    oo.push_back(ffi3<vm_text_t, vm_ptr_t, vm_int_t, vm_int_t>(vm, "CMark", "cmark_render_latex",
                [](vm_ptr_t p, vm_int_t n0, vm_int_t n1){return to_uni(cmark_render_latex( (cmark_node*) p,n0,n1));}).clone());
    oo.push_back(ffi3<vm_text_t, vm_ptr_t, vm_int_t, vm_int_t>(vm, "CMark", "cmark_render_commonmark",
                [](vm_ptr_t p, vm_int_t n0, vm_int_t n1){return to_uni(cmark_render_commonmark( (cmark_node*) p,n0,n1));}).clone());


    // inspection
    oo.push_back(ffi1<vm_int_t, vm_ptr_t>(vm, "CMark", "cmark_node_get_type",
                [](vm_ptr_t p){return (vm_int_t) cmark_node_get_type( (cmark_node*) p);}).clone());

    oo.push_back(ffi1<vm_ptr_t, vm_ptr_t>(vm, "CMark", "cmark_node_first_child",
                [](vm_ptr_t p){return (vm_ptr_t) cmark_node_first_child( (cmark_node*) p);}).clone());
    oo.push_back(ffi1<vm_ptr_t, vm_ptr_t>(vm, "CMark", "cmark_node_next",
                [](vm_ptr_t p){return (vm_ptr_t) cmark_node_next( (cmark_node*) p);}).clone());

    oo.push_back(ffi1<vm_text_t, vm_ptr_t>(vm, "CMark", "cmark_node_get_literal",
                [](vm_ptr_t p){return to_uni(cmark_node_get_literal( (cmark_node*) p));}).clone());
    oo.push_back(ffi1<vm_text_t, vm_ptr_t>(vm, "CMark", "cmark_node_get_url",
                [](vm_ptr_t p){return to_uni(cmark_node_get_url( (cmark_node*) p));}).clone());
    oo.push_back(ffi1<vm_text_t, vm_ptr_t>(vm, "CMark", "cmark_node_get_title",
                [](vm_ptr_t p){return to_uni(cmark_node_get_title( (cmark_node*) p));}).clone());
    oo.push_back(ffi1<vm_int_t, vm_ptr_t>(vm, "CMark", "cmark_node_get_heading_level",
                [](vm_ptr_t p){return (vm_int_t) cmark_node_get_heading_level( (cmark_node*) p);}).clone());
    oo.push_back(ffi1<vm_int_t, vm_ptr_t>(vm, "CMark", "cmark_node_get_list_type",
                [](vm_ptr_t p){return (vm_int_t) cmark_node_get_list_type( (cmark_node*) p);}).clone());
    oo.push_back(ffi1<vm_bool_t, vm_ptr_t>(vm, "CMark", "cmark_node_get_list_tight",
                [](vm_ptr_t p){return (vm_bool_t) cmark_node_get_list_tight( (cmark_node*) p);}).clone());
    oo.push_back(ffi1<vm_int_t, vm_ptr_t>(vm, "CMark", "cmark_node_get_list_start",
                [](vm_ptr_t p){return (vm_int_t) cmark_node_get_list_start( (cmark_node*) p);}).clone());
    oo.push_back(ffi1<vm_int_t, vm_ptr_t>(vm, "CMark", "cmark_node_get_list_delim",
                [](vm_ptr_t p){return (vm_int_t) cmark_node_get_list_delim( (cmark_node*) p);}).clone());
    oo.push_back(ffi1<vm_text_t, vm_ptr_t>(vm, "CMark", "cmark_node_get_fence_info",
                [](vm_ptr_t p){return to_uni(cmark_node_get_fence_info( (cmark_node*) p));}).clone());
    oo.push_back(ffi1<vm_int_t, vm_ptr_t>(vm, "CMark", "cmark_node_get_start_line",
                [](vm_ptr_t p){return (vm_int_t) cmark_node_get_start_line( (cmark_node*) p);}).clone());
    oo.push_back(ffi1<vm_int_t, vm_ptr_t>(vm, "CMark", "cmark_node_get_start_column",
                [](vm_ptr_t p){return (vm_int_t) cmark_node_get_start_column( (cmark_node*) p);}).clone());
    oo.push_back(ffi1<vm_int_t, vm_ptr_t>(vm, "CMark", "cmark_node_get_end_line",
                [](vm_ptr_t p){return (vm_int_t) cmark_node_get_end_line( (cmark_node*) p);}).clone());
    oo.push_back(ffi1<vm_int_t, vm_ptr_t>(vm, "CMark", "cmark_node_get_end_column",
                [](vm_ptr_t p){return (vm_int_t) cmark_node_get_end_column( (cmark_node*) p);}).clone());
    oo.push_back(ffi1<vm_text_t, vm_ptr_t>(vm, "CMark", "cmark_node_get_on_enter",
                [](vm_ptr_t p){return to_uni(cmark_node_get_on_enter( (cmark_node*) p));}).clone());
    oo.push_back(ffi1<vm_text_t, vm_ptr_t>(vm, "CMark", "cmark_node_get_on_exit",
                [](vm_ptr_t p){return to_uni(cmark_node_get_on_exit( (cmark_node*) p));}).clone());

    // construction
    oo.push_back(ffi2<vm_int_t, vm_ptr_t, vm_ptr_t>(vm, "CMark", "cmark_node_append_child",
                [](vm_ptr_t p0, vm_ptr_t p1){return (vm_int_t) cmark_node_append_child( (cmark_node*) p0,  (cmark_node*) p1);}).clone());
    oo.push_back(ffi2<vm_int_t, vm_ptr_t, vm_text_t>(vm, "CMark", "cmark_node_set_literal",
                [](vm_ptr_t p, vm_text_t s){auto cc = from_uni(s); auto r = cmark_node_set_literal( (cmark_node*) p, cc); delete[] cc; return (vm_int_t) r;}).clone());
    oo.push_back(ffi2<vm_int_t, vm_ptr_t, vm_text_t>(vm, "CMark", "cmark_node_set_url",
                [](vm_ptr_t p, vm_text_t s){auto cc = from_uni(s); auto r = cmark_node_set_url( (cmark_node*) p, cc); delete[] cc; return (vm_int_t) r;}).clone());
    oo.push_back(ffi2<vm_int_t, vm_ptr_t, vm_text_t>(vm, "CMark", "cmark_node_set_title",
                [](vm_ptr_t p, vm_text_t s){auto cc = from_uni(s); auto r = cmark_node_set_title( (cmark_node*) p, cc); delete[] cc; return (vm_int_t) r;}).clone());
    oo.push_back(ffi2<vm_int_t, vm_ptr_t, vm_int_t>(vm, "CMark", "cmark_node_set_heading_level",
                [](vm_ptr_t p, vm_int_t n){return (vm_int_t) cmark_node_set_heading_level( (cmark_node*) p, n);}).clone());
    oo.push_back(ffi2<vm_int_t, vm_ptr_t, vm_int_t>(vm, "CMark", "cmark_node_set_list_type",
                [](vm_ptr_t p, vm_int_t n){return (vm_int_t) cmark_node_set_list_type( (cmark_node*) p, (cmark_list_type) n);}).clone());
    oo.push_back(ffi2<vm_int_t, vm_ptr_t, vm_bool_t>(vm, "CMark", "cmark_node_set_list_tight",
                [](vm_ptr_t p, vm_bool_t b){return (vm_int_t) cmark_node_set_list_tight( (cmark_node*) p, b);}).clone());
    oo.push_back(ffi2<vm_int_t, vm_ptr_t, vm_int_t>(vm, "CMark", "cmark_node_set_list_start",
                [](vm_ptr_t p, vm_int_t n){return (vm_int_t) cmark_node_set_list_start( (cmark_node*) p, n);}).clone());
    oo.push_back(ffi2<vm_int_t, vm_ptr_t, vm_int_t>(vm, "CMark", "cmark_node_set_list_delim",
                [](vm_ptr_t p, vm_int_t n){return (vm_int_t) cmark_node_set_list_delim( (cmark_node*) p, (cmark_delim_type) n);}).clone());
    oo.push_back(ffi2<vm_int_t, vm_ptr_t, vm_text_t>(vm, "CMark", "cmark_node_set_fence_info",
                [](vm_ptr_t p, vm_text_t s){auto cc = from_uni(s); auto r = cmark_node_set_fence_info( (cmark_node*) p, cc); delete[] cc; return (vm_int_t) r;}).clone());
    oo.push_back(ffi2<vm_int_t, vm_ptr_t, vm_text_t>(vm, "CMark", "cmark_node_set_on_enter",
                [](vm_ptr_t p, vm_text_t s){auto cc = from_uni(s); auto r = cmark_node_set_on_enter( (cmark_node*) p, cc); delete[] cc; return (vm_int_t) r;}).clone());
    oo.push_back(ffi2<vm_int_t, vm_ptr_t, vm_text_t>(vm, "CMark", "cmark_node_set_on_exit",
                [](vm_ptr_t p, vm_text_t s){auto cc = from_uni(s); auto r = cmark_node_set_on_exit( (cmark_node*) p, cc); delete[] cc; return (vm_int_t) r;}).clone());


    return oo;
}
