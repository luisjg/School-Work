<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class User_classes extends Model
{
    protected $fillable = [
        'user_id',
        'class_id',
        'date_taken',
        'note'
    ];

    public function user()
    {
        return $this->belongsTo('App\User');
    }

    public function classes()
    {
        return $this->belongsTo('App\classes');
    }
}
