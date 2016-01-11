<?php namespace App\Http\Controllers;

use Auth;
use App\Article;
use App\Tag;
use App\Http\Requests;
// for object validation
use App\Http\Requests\ArticleRequest;
use App\Http\Controllers\Controller;
use Carbon\Carbon;
// for controller validation
// use Illuminate\Http\Request;f

class ArticlesController extends Controller {

	public function __construct()
	{
		$this->middleware('auth', ['only' => 'create']);
	}
	//
	public function index()
	{
		// fetches all the articles
		// $articles = Article::latest('published_at')->get();
		// fetches all the articles where they have already been published
		// too long and messy let's make it into a scope
		$articles = Article::latest('published_at')->published()->get();
		return view('articles.index', compact('articles'));
	}

	public function show(Article $article)
	{
		// more simpler way of showing a 404
		// $article = Article::findOrFail($id);
		// another way to display a 404
		// if(is_null($article)){
		// 	abort(404);
		// }

		// dd($article->published_at);
		return view('articles.show', compact('article'));
	}

	public function create()
	{
		// get all the tags
		$tags = Tag::lists('name', 'id');
		return view('articles.create', compact('tags'));
	}

	/* one way controller offloads to object and proceeds if
		 everything is ok*/
	/*public function store(CreateArticleRequest $request){
		// validation occurs automatically
		// no need for facade
		Article::create($request->all());
		// one way to send form data to a new article
		// $input = Request::all();
		// Article::create($input);

		// another way is to inline it
		// Article::create(Request::all());
		return redirect('articles');
	}*/

	/* controller handles the validation */
	public function store(ArticleRequest $request)
	{
		// save an article		
		// Article::create($request->all());

		// add user to article
		// Auth::user()->articles()->create($request->all());
		
		// lets store article and tag
		$article = Auth::user()->articles()->create($request->all());
		$tagIds = $request->input('tag_list');
		$article->tags()->attach($tagIds);

		// another way
		// $article = new Article($request->all());
		// Auth::user()->articles()->save($article);
		
		// flash a message
		// session()->flash('flash_message', 'Your article has been created!');
		// session()->flash('flash_message_important', true);
		// another way
		// \Session::flash('flash_message', 'Your article has been created!');
		// return redirect('articles');
		
		// yet another way to flash a message
		// return redirect('articles')->with([
		// 	'flash_message' => 'Your article has been created!',
		// 	'flash_message_important' => true
		// ]);

		// yet another way
		flash()->success('You are now logged in!');
		return redirect('articles')->with('flash_message');
	}

	public function edit(Article $article)
	{
		$tags = Tag::lists('name', 'id');
		return view('articles.edit',compact('article', 'tags'));
	}

	public function update(Article $article, ArticleRequest $request)
	{
		$article->update($request->all());
		// update the tags
		$article->syncTags($article, $request->input('tag_list'))
		return redirect('articles');
	}

	private function syncTags(Article $article, array $tags)
	{
		$artcle->tags()->sync($tags);
	}

}
